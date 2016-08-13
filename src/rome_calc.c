#include <stddef.h>
#include "rome_calc.h"
#include "rome_calc_err.h"
#include "roman.h"

enum {
    ROME_CALC_ADD_OP,
    ROME_CALC_SUBTRACT_OP
};

static int arithmetic_input_validation(char const *a, char const *b,
        char *buffer, RomeCalcError *err)
{
    if (buffer == NULL) {
        rome_calc_error(err, ROME_CALC_E_NULL_BUFFER);
        return 0;
    }

    if (buffer[0] != '\0') {
        rome_calc_error(err, ROME_CALC_E_BUFFER_NOT_EMPTY);
        return 0;
    }

    if (a == NULL || b == NULL) {
        rome_calc_error(err, ROME_CALC_E_INPUT_NULL);
        return 0;
    }

    if (a[0] == '\0' || b[0] == '\0') {
        rome_calc_error(err, ROME_CALC_E_EMPTY_STRING);
        return 0;
    }

    return 1;
}

static void arithmetic(char const *a, char const *b, char *buffer,
        RomeCalcError *err, int operation) {

    if (!arithmetic_input_validation(a, b, buffer, err)) {
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

    if (operation == ROME_CALC_ADD_OP) {
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
    arithmetic(a, b, buffer, err, ROME_CALC_ADD_OP);
}

void rome_subtract(char const *a, char const *b, char *buffer,
        RomeCalcError *err)
{
    arithmetic(a, b, buffer, err, ROME_CALC_SUBTRACT_OP);
}
