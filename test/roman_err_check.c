#include <check.h>
#include "roman_err_check.h"

#include "../src/roman.h"

START_TEST (to_roman_success_err)
{
    char result[2] = {0};
    RomanError err;
    to_roman(5, result, &err);
    ck_assert_int_eq(ROMAN_E_SUCCESS, err.code);
}
END_TEST

START_TEST (to_roman_null_buffer_err)
{
    RomanError err;
    to_roman(5, NULL, &err); 
    ck_assert_int_eq(ROMAN_E_NULL_BUFFER, err.code);
}
END_TEST

START_TEST (to_roman_lower_bound_err)
{
    RomanError err;
    to_roman(0, NULL, &err);
    ck_assert_int_eq(ROMAN_E_ARABIC_LT_ONE, err.code);
}
END_TEST

START_TEST (to_roman_upper_bound_err)
{
    RomanError err;
    to_roman(4000, NULL, &err);
    ck_assert_int_eq(ROMAN_E_ARABIC_GT_3999, err.code);
}
END_TEST

Suite * roman_err_suite_create(void)
{
    Suite *suite;
    suite = suite_create("roman numeral converter errors");

    TCase *tcase;
    tcase = tcase_create("core");

    tcase_add_test(tcase, to_roman_null_buffer_err);
    tcase_add_test(tcase, to_roman_success_err);
    tcase_add_test(tcase, to_roman_lower_bound_err);
    tcase_add_test(tcase, to_roman_upper_bound_err);

    suite_add_tcase(suite, tcase);
    return suite;
}

