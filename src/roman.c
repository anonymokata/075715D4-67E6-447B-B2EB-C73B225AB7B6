#include <string.h>
#include "roman.h"
#include "roman_err.h"

typedef struct {
    int arabic;
    char *roman;
} Numeral; 

static Numeral numerals[] = {
    { 1000, "M" },
    { 900, "CM" },
    { 500, "D" },
    { 400, "CD" },
    { 100, "C" },
    { 90, "XC" },
    { 50, "L" },
    { 40, "XL" },
    { 10, "X" },
    { 9, "IX" },
    { 5, "V" },
    { 4, "IV" },
    { 1, "I" },
    { 0, "?" }
};

static void repeat_append(char *dest, char const *src, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        strcat(dest, src);
    }
}

static int validate_to_roman_inputs(int arabic, char *buffer, RomanError *err)
{
    if (arabic <= 0) {
        roman_error(err, ROMAN_E_ARABIC_LT_ONE);
        return 0;
    }

    if (arabic >= 4000) {
        roman_error(err, ROMAN_E_ARABIC_GT_3999);
        return 0;
    }

    if (buffer == NULL) {
        roman_error(err, ROMAN_E_NULL_BUFFER);
        return 0;
    }

    if (buffer[0] != '\0') {
        roman_error(err, ROMAN_E_BUFFER_NOT_EMPTY);
        return 0;
    }

    return 1;
}

void to_roman(int arabic, char *buffer, RomanError *err)
{
    if(!validate_to_roman_inputs(arabic, buffer, err)) {
        return;
    }

    int remaining = arabic;
   
    Numeral *next;
    for (next = numerals; next->arabic != 0; next++) {
        int repetitions = remaining / next->arabic;
        remaining %= next->arabic; 

        repeat_append(buffer, next->roman, repetitions);
    }

    roman_error(err, ROMAN_E_SUCCESS);
}

static int get_digit(char const *in, int one_or_two_chars)
{
    char buffer[3];
    memset(buffer, 0, sizeof(buffer));
    memcpy(buffer, in, one_or_two_chars);

    Numeral *next;
    for (next = numerals; next->arabic != 0; next++) {
        if (strcmp(buffer, next->roman) == 0) {
            break;
        }
    }

    int no_digit_found = (one_or_two_chars == 1 && next->arabic == 0);
    if (no_digit_found) {
        return -1;
    }

    return next->arabic;
}

static char * get_highest_roman_digit(int n) {
    Numeral *next;
    for (next = numerals; next->arabic != 0; next++) {
        if (n >= next->arabic) {
            break;
        }
    }
    return next->roman;
}

static int validate_to_arabic_inputs(char const *roman, RomanError *err)
{
    if (roman == NULL) {
        roman_error(err, ROMAN_E_INPUT_NULL);
        return 0;
    }

    if (roman[0] == '\0') {
        roman_error(err, ROMAN_E_EMPTY_STRING);
        return 0;
    }

    return 1;
}

static int to_arabic_validation(char const *position,
        int *result, int *prev_result,
        int *repeat_total, int *repeat_digits,
        RomanError *err)
{
    if (*result < 0) {
        roman_error(err, ROMAN_E_INVALID_NUMERAL);   
        return 0;
    } 

    if (*result == *prev_result) {
        *repeat_total += *result;
        (*repeat_digits)++;
    } else {
        *repeat_total = *result;
        *repeat_digits = 1;
    }

    if (*prev_result != 0 && *prev_result < *result) {
        roman_error(err, ROMAN_E_INVALID_ORDER);
        return 0;
    }

    if (*repeat_digits == 4) {
        roman_error(err, ROMAN_E_QUADS);
        return 0;
    }

    if (*repeat_digits >= 2) {
        char *digit = get_highest_roman_digit(*repeat_total);
        int same_symbol = (strncmp(position, digit, 1) == 0);

        if (!same_symbol && strlen(digit) < *repeat_digits) {
            roman_error(err, ROMAN_E_INVALID_REPEAT);
            return 0;
        }
    }

    *prev_result = *result;

    return 1;
}

int to_arabic(char const *roman, RomanError *err)
{
    if (!validate_to_arabic_inputs(roman, err)) {
        return 0;
    }

    int length = strlen(roman),
        accumulator = 0,
        repeat_total = 0,
        repeat_digits = 1,
        prev_result = 0;

    int i;
    for (i = 0; i < length; i++) {
        char const *position = roman + i;
        int result = get_digit(position, 2);
        if (result > 0) {
            i++;
        } else {
            result = get_digit(position, 1);
        }

        if(!to_arabic_validation(position,
                    &result, &prev_result,
                    &repeat_total, &repeat_digits, err)) {
            return 0;
        }

        accumulator += result;
    }

    roman_error(err, ROMAN_E_SUCCESS);
    return accumulator;
}
