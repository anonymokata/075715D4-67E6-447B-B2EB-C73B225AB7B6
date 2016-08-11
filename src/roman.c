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

static void repeat_append(char *dest, char const *src, int n) {
    int i;
    for (i = 0; i < n; i++) {
        strcat(dest, src);
    }
}

void to_roman(int arabic, char *roman, RomanError **err)
{
    int remaining = arabic;
   
    Numeral *next;
    for (next = numerals; next->arabic != 0; next++) {
        int repetitions = remaining / next->arabic;
        remaining %= next->arabic; 

        repeat_append(roman, next->roman, repetitions);
    }
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
    return next->arabic;
}

int to_arabic(char const *roman, RomanError **err)
{
    int length = strlen(roman),
        accumulator = 0,
        i;

    for (i = 0; i < length; i++) {
        char const *position = roman + i;
        int result = get_digit(position, 2);
        if (result > 0) {
            i++;
        } else {
            result = get_digit(position, 1);
        }
        accumulator += result;
    }

    return accumulator;
}
