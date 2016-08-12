#ifndef ROMAN_H
#define ROMAN_H

#include "roman_err.h"

extern void to_roman(int arabic, char *roman, RomanError *err);
extern int to_arabic(char const *roman, RomanError *err);

#endif /* ROMAN_H */
