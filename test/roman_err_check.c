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

START_TEST (to_roman_empty_str_buffer_err)
{
    char *buffer = "stuff";
    RomanError err;
    to_roman(5, buffer, &err);
    ck_assert_int_eq(ROMAN_E_BUFFER_NOT_EMPTY, err.code);
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

START_TEST (to_arabic_success_err)
{
    RomanError err;
    to_arabic("X", &err);
    ck_assert_int_eq(ROMAN_E_SUCCESS, err.code);
}
END_TEST

START_TEST (to_arabic_input_null_err)
{
    RomanError err;
    to_arabic(NULL, &err);
    ck_assert_int_eq(ROMAN_E_INPUT_NULL, err.code);
}
END_TEST

START_TEST (to_arabic_double_digit_repeat_err)
{
    RomanError err;
    to_arabic("IVIV", &err);
    ck_assert_int_eq(ROMAN_E_DOUBLE_REPEAT, err.code);
}
END_TEST

START_TEST (to_arabic_invalid_order_err)
{
    RomanError err;
    to_arabic("IM", &err);
    ck_assert_int_eq(ROMAN_E_INVALID_ORDER, err.code);
}
END_TEST

START_TEST (to_arabic_invalid_numeral_err)
{
    RomanError err;
    to_arabic("NOPE", &err);
    ck_assert_int_eq(ROMAN_E_INVALID_NUMERAL, err.code);
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
    tcase_add_test(tcase, to_roman_empty_str_buffer_err);
    tcase_add_test(tcase, to_arabic_success_err);
    tcase_add_test(tcase, to_arabic_input_null_err);
    tcase_add_test(tcase, to_arabic_double_digit_repeat_err);
    tcase_add_test(tcase, to_arabic_invalid_order_err);
    tcase_add_test(tcase, to_arabic_invalid_numeral_err);

    suite_add_tcase(suite, tcase);
    return suite;
}

