#include <string.h>
#include "roman.h"

typedef struct {
    int arabic;
    char * roman;
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

static char * next_highest_digit(int *pool)
{
    int i;
    for (i = 0; numerals[i].arabic != 0; i++) {
        if (*pool >= numerals[i].arabic) {
            *pool -= numerals[i].arabic;
            return numerals[i].roman;
        }
    }
    return "?";
}

void to_roman(int arabic, char *roman)
{
    int pool = arabic;
    while (pool > 0) {
        strcat(roman, next_highest_digit(&pool));
    }
}

static int convert_digit(char const *digit)
{
    int i;
    for (i = 0; numerals[i].arabic != 0; i++) {
        if (strcmp(digit, numerals[i].roman) == 0) {
            return numerals[i].arabic;
        }
    }
    return 0;
}

static int peek_left_is_lesser(int index, char const *roman)
{
    char left[2];
    memset(left, 0, sizeof(left));
    memcpy(left, roman + index - 1, 1);
    
    char right[2];
    memset(right, 0, sizeof(right));
    memcpy(right, roman + index, 1);

    return convert_digit(left) < convert_digit(right);
}

int to_arabic(char const *roman)
{
    int accumulator = 0;
    int index;
    char buffer[3];

    // work from right to left
    index = (int) strlen(roman) - 1;
    while (index > -1) {
        memset(buffer, 0, sizeof(buffer));
        if (index == 0) {
            memcpy(buffer, roman, 1);
            accumulator += convert_digit(buffer);    
            return accumulator;
        } 
        if (peek_left_is_lesser(index, roman)) {
            memcpy(buffer, roman + index - 1, 2);
            index -= 2;
        } else {
            memcpy(buffer, roman + index, 1);
            index -= 1;
        }
        accumulator += convert_digit(buffer);
    }

    return accumulator;
}
