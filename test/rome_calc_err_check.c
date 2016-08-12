#include <check.h>
#include <string.h>
#include "rome_calc_err_check.h"

#include "../src/rome_calc.h"

#define reset() \
    memset(&err, 0, sizeof(RomeCalcError)); \
    memset(buffer, 0, sizeof(buffer));

START_TEST (rome_calc_success_err_check)
{
    RomeCalcError err;
    char buffer[3] = {0};

    rome_add("I", "I", buffer, &err);
    ck_assert_int_eq(ROME_CALC_E_SUCCESS, err.code);

    reset();
    rome_subtract("II", "I", buffer, &err);
    ck_assert_int_eq(ROME_CALC_E_SUCCESS, err.code);
}
END_TEST

START_TEST (rome_calc_null_buffer_err_check)
{
    RomeCalcError err;

    rome_add("I", "I", NULL, &err);
    ck_assert_int_eq(ROME_CALC_E_NULL_BUFFER, err.code);

    memset(&err, 0, sizeof(RomeCalcError));
    rome_subtract("II", "I", NULL, &err);
    ck_assert_int_eq(ROME_CALC_E_NULL_BUFFER, err.code);
}
END_TEST

START_TEST (rome_calc_input_null_err_check)
{
    RomeCalcError err;
    char buffer[3] = {0};

    rome_add(NULL, "I", buffer, &err);
    ck_assert_int_eq(ROME_CALC_E_INPUT_NULL, err.code);

    reset();
    rome_add("I", NULL, buffer, &err);
    ck_assert_int_eq(ROME_CALC_E_INPUT_NULL, err.code);

    reset();
    rome_subtract(NULL, "I", buffer, &err);
    ck_assert_int_eq(ROME_CALC_E_INPUT_NULL, err.code);

    reset();
    rome_subtract("II", NULL, buffer, &err);
    ck_assert_int_eq(ROME_CALC_E_INPUT_NULL, err.code);
}
END_TEST

START_TEST (rome_calc_buffer_not_empty_err_check)
{
    RomeCalcError err;
    char buffer[6] = "hello";

    rome_add("I", "I", buffer, &err);
    ck_assert_int_eq(ROME_CALC_E_BUFFER_NOT_EMPTY, err.code);

    memset(&err, 0, sizeof(RomeCalcError));
    rome_subtract("II", "I", buffer, &err);
    ck_assert_int_eq(ROME_CALC_E_BUFFER_NOT_EMPTY, err.code);
}
END_TEST

START_TEST (rome_calc_empty_input_string)
{
    RomeCalcError err;
    char buffer[3] = {0};

    rome_add("I", "", buffer, &err);
    ck_assert_int_eq(ROME_CALC_E_EMPTY_STRING, err.code);

    reset();
    rome_add("I", "", buffer, &err);
    ck_assert_int_eq(ROME_CALC_E_EMPTY_STRING, err.code);

    reset();
    rome_subtract("II", "", buffer, &err);
    ck_assert_int_eq(ROME_CALC_E_EMPTY_STRING, err.code);

    reset();
    rome_subtract("", "I", buffer, &err);
    ck_assert_int_eq(ROME_CALC_E_EMPTY_STRING, err.code);
}
END_TEST

START_TEST (rome_calc_to_arabic_err)
{
    RomeCalcError err;
    char buffer[16] = {0};

    rome_add("I", "QUACK", buffer, &err);
    ck_assert_int_eq(ROME_CALC_E_TO_ARABIC, err.code);

    reset();
    rome_add("DUCK", "I", buffer, &err);
    ck_assert_int_eq(ROME_CALC_E_TO_ARABIC, err.code);

    reset();
    rome_subtract("II", "QUACK", buffer, &err);
    ck_assert_int_eq(ROME_CALC_E_TO_ARABIC, err.code);

    reset();
    rome_subtract("DUCK", "I", buffer, &err);
    ck_assert_int_eq(ROME_CALC_E_TO_ARABIC, err.code);
}
END_TEST

START_TEST (rome_calc_to_roman_err)
{
    RomeCalcError err;
    char buffer[16] = {0};

    rome_add("MMMCMXCIX", "MMMCMXCIX", buffer, &err);
    ck_assert_int_eq(ROME_CALC_E_TO_ROMAN, err.code);
}
END_TEST

START_TEST (helpful_error_messages)
{
    RomeCalcError err;

    rome_calc_error(&err, ROME_CALC_E_SUCCESS);
    ck_assert_str_eq("success", err.message);
    rome_calc_error(&err, ROME_CALC_E_NULL_BUFFER);
    ck_assert_str_eq("output buffer is null", err.message);
    rome_calc_error(&err, ROME_CALC_E_INPUT_NULL);
    ck_assert_str_eq("a null pointer operand was passed in", err.message);
    rome_calc_error(&err, ROME_CALC_E_BUFFER_NOT_EMPTY);
    ck_assert_str_eq("output buffer not empty", err.message);
    rome_calc_error(&err, ROME_CALC_E_EMPTY_STRING);
    ck_assert_str_eq("an empty string operand was passed in", err.message);
    rome_calc_error(&err, ROME_CALC_E_TO_ROMAN);
    ck_assert_str_eq("conversion of arabic to roman failed", err.message);
    rome_calc_error(&err, ROME_CALC_E_TO_ARABIC);
    ck_assert_str_eq("conversion of roman to arabic failed", err.message);
    rome_calc_error(&err, ROME_CALC_E_UNKNOWN);
    ck_assert_str_eq("unknown", err.message);
}
END_TEST

Suite * rome_calc_err_suite_create(void)
{
    Suite *suite;
    suite = suite_create("roman numeral calculator errors");

    TCase *tcase;
    tcase = tcase_create("core");

    tcase_add_test(tcase, rome_calc_success_err_check);
    tcase_add_test(tcase, rome_calc_null_buffer_err_check);
    tcase_add_test(tcase, rome_calc_input_null_err_check);
    tcase_add_test(tcase, rome_calc_buffer_not_empty_err_check);
    tcase_add_test(tcase, rome_calc_empty_input_string);
    tcase_add_test(tcase, rome_calc_to_roman_err);
    tcase_add_test(tcase, rome_calc_to_arabic_err);
    tcase_add_test(tcase, helpful_error_messages);

    suite_add_tcase(suite, tcase);
    return suite;
}

