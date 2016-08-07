#include <stdio.h>
#include <check.h>
#include "roman_check.h"

#include "../src/roman.h"

START_TEST (convert_1_to_I)
{
    char result[2] = {0};
    arabic_to_roman(1, result);
    ck_assert_str_eq("I", result); 
}
END_TEST

START_TEST (convert_3_to_III)
{
    char result[4] = {0};
    arabic_to_roman(3, result);
    ck_assert_str_eq("III", result);
}
END_TEST

START_TEST (convert_4_to_IV)
{
    char result[3] = {0};
    arabic_to_roman(4, result);
    ck_assert_str_eq("IV", result);
}
END_TEST

START_TEST (convert_5_to_V)
{
    char result[2] = {0};
    arabic_to_roman(5, result);
    ck_assert_str_eq("V", result);
}
END_TEST

Suite * roman_suite_create(void)
{
    Suite *suite;
    suite = suite_create("roman");

    TCase *tcase;
    tcase = tcase_create("core");

    tcase_add_test(tcase, convert_1_to_I);
    tcase_add_test(tcase, convert_3_to_III);
    tcase_add_test(tcase, convert_4_to_IV);
    tcase_add_test(tcase, convert_5_to_V);

    suite_add_tcase(suite, tcase);
    return suite;
}

