#include <check.h>
#include <string.h>
#include "rome_calc_err_check.h"

#include "../src/rome_calc.h"

START_TEST (rome_calc_success_err_check)
{
    RomeCalcError err;

    char result[3] = {0};
    rome_add("I", "I", result, &err);
    ck_assert_int_eq(ROME_CALC_E_SUCCESS, err.code);

    memset(result, 0, sizeof(result));
    rome_subtract("II", "I", result, &err);
    ck_assert_int_eq(ROME_CALC_E_SUCCESS, err.code);
}
END_TEST

Suite * rome_calc_err_suite_create(void)
{
    Suite *suite;
    suite = suite_create("roman numeral calculator errors");

    TCase *tcase;
    tcase = tcase_create("core");

    tcase_add_test(tcase, rome_calc_success_err_check);

    suite_add_tcase(suite, tcase);
    return suite;
}

