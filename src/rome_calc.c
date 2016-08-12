#include <stddef.h>
#include "rome_calc.h"
#include "rome_calc_err.h"
#include "roman.h"

void rome_add(char const *a, char const *b, char *buffer,
        RomeCalcError *err)
{
    if (buffer == NULL) {
        rome_calc_error(err, ROME_CALC_E_NULL_BUFFER);
        return;
    }

    int a_num = to_arabic(a, NULL);
    int b_num = to_arabic(b, NULL);
    to_roman(a_num + b_num, buffer, NULL); 
    rome_calc_error(err, ROME_CALC_E_SUCCESS);
}

void rome_subtract(char const *a, char const *b, char *buffer,
        RomeCalcError *err)
{
    if (buffer == NULL) {
        rome_calc_error(err, ROME_CALC_E_NULL_BUFFER);
        return;
    }

    int a_num = to_arabic(a, NULL);
    int b_num = to_arabic(b, NULL);
    to_roman(a_num - b_num, buffer, NULL);
    rome_calc_error(err, ROME_CALC_E_SUCCESS);
}
