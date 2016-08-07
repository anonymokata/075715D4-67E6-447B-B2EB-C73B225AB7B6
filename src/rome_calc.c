#include "rome_calc.h"
#include "roman.h"

void rome_add(char const *a, char const *b, char *result)
{
    int a_num = to_arabic(a);
    int b_num = to_arabic(b);
    to_roman(a_num + b_num, result); 
}
