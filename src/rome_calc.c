#include <stddef.h>
#include "rome_calc.h"
#include "roman.h"

void rome_add(char const *a, char const *b, char *result)
{
    int a_num = to_arabic(a, NULL);
    int b_num = to_arabic(b, NULL);
    to_roman(a_num + b_num, result, NULL); 
}

void rome_subtract(char const *a, char const *b, char *result)
{
    int a_num = to_arabic(a, NULL);
    int b_num = to_arabic(b, NULL);
    to_roman(a_num - b_num, result, NULL);
}
