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

Suite * roman_err_suite_create(void)
{
    Suite *suite;
    suite = suite_create("roman numeral converter errors");

    TCase *tcase;
    tcase = tcase_create("core");

    tcase_add_test(tcase, to_roman_null_buffer_err);
    tcase_add_test(tcase, to_roman_success_err);

    suite_add_tcase(suite, tcase);
    return suite;
}

