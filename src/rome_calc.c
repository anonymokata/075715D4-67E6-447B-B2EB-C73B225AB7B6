#include <stddef.h>
#include "rome_calc.h"
#include "rome_calc_err.h"
#include "roman.h"

enum {
    ROME_ADD_OP,
    ROME_SUBTRACT_OP
};

static void arithmetic(char const *a, char const *b, char *buffer,
        RomeCalcError *err, int operation) {

    if (buffer == NULL) {
        rome_calc_error(err, ROME_CALC_E_NULL_BUFFER);
        return;
    }

    if (buffer[0] != '\0') {
        rome_calc_error(err, ROME_CALC_E_BUFFER_NOT_EMPTY);
        return;
    }

    if (a == NULL || b == NULL) {
        rome_calc_error(err, ROME_CALC_E_INPUT_NULL);
        return;
    }

    if (a[0] == '\0' || b[0] == '\0') {
        rome_calc_error(err, ROME_CALC_E_EMPTY_STRING);
        return;
    }

    RomanError roman_err;

    int a_num = to_arabic(a, &roman_err);
    if (roman_err.code != ROMAN_E_SUCCESS) {
        rome_calc_error(err, ROME_CALC_E_TO_ARABIC);
        return;
    }

    int b_num = to_arabic(b, &roman_err);
    if (roman_err.code != ROMAN_E_SUCCESS) {
        rome_calc_error(err, ROME_CALC_E_TO_ARABIC);
        return;
    }

    if (operation == ROME_ADD_OP) {
        to_roman(a_num + b_num, buffer, &roman_err); 
    } else {
        to_roman(a_num - b_num, buffer, &roman_err);
    }

    if (roman_err.code != ROMAN_E_SUCCESS) {
        rome_calc_error(err, ROME_CALC_E_TO_ROMAN);
        return;
    }

    rome_calc_error(err, ROME_CALC_E_SUCCESS);
}

void rome_add(char const *a, char const *b, char *buffer,
        RomeCalcError *err)
{
    arithmetic(a, b, buffer, err, ROME_ADD_OP);
}

void rome_subtract(char const *a, char const *b, char *buffer,
        RomeCalcError *err)
{
    arithmetic(a, b, buffer, err, ROME_SUBTRACT_OP);
}
