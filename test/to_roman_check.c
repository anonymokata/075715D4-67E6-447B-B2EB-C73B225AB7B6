#include <stdio.h>
#include <check.h>
#include "to_roman_check.h"

#include "../src/roman.h"

START_TEST (convert_1_to_I)
{
    char result[2] = {0};
    to_roman(1, result);
    ck_assert_str_eq("I", result); 
}
END_TEST

START_TEST (convert_3_to_III)
{
    char result[4] = {0};
    to_roman(3, result);
    ck_assert_str_eq("III", result);
}
END_TEST

START_TEST (convert_4_to_IV)
{
    char result[3] = {0};
    to_roman(4, result);
    ck_assert_str_eq("IV", result);
}
END_TEST

START_TEST (convert_5_to_V)
{
    char result[2] = {0};
    to_roman(5, result);
    ck_assert_str_eq("V", result);
}
END_TEST

START_TEST (convert_6_to_VI)
{
    char result[3] = {0};
    to_roman(6, result);
    ck_assert_str_eq("VI", result);
}
END_TEST

START_TEST (convert_9_to_IX)
{
    char result[3] = {0};
    to_roman(9, result);
    ck_assert_str_eq("IX", result);
}
END_TEST

START_TEST (convert_10_to_X)
{
    char result[2] = {0};
    to_roman(10, result);
    ck_assert_str_eq("X", result);
}
END_TEST

START_TEST (convert_40_to_XL)
{
    char result[3] = {0};
    to_roman(40, result);
    ck_assert_str_eq("XL", result);
}
END_TEST

START_TEST (convert_50_to_L)
{
    char result[2] = {0};
    to_roman(50, result);
    ck_assert_str_eq("L", result);
}
END_TEST

START_TEST (convert_90_to_XC)
{
    char result[3] = {0};
    to_roman(90, result);
    ck_assert_str_eq("XC", result);
}
END_TEST

START_TEST (convert_100_to_C)
{
    char result[2] = {0};
    to_roman(100, result);
    ck_assert_str_eq("C", result);
}
END_TEST

START_TEST (convert_400_to_CD)
{
    char result[3] = {0};
    to_roman(400, result);
    ck_assert_str_eq("CD", result);
}
END_TEST

START_TEST (convert_500_to_D)
{
    char result[2] = {0};
    to_roman(500, result);
    ck_assert_str_eq("D", result);
}
END_TEST

START_TEST (convert_900_to_CM)
{
    char result[3] = {0};
    to_roman(900, result);
    ck_assert_str_eq("CM", result);
}
END_TEST

START_TEST (convert_1000_to_M)
{
    char result[2] = {0};
    to_roman(1000, result);
    ck_assert_str_eq("M", result);
}
END_TEST

START_TEST (convert_3999_to_MMMCMXCIX)
{
    char result[10] = {0};
    to_roman(3999, result);
    ck_assert_str_eq("MMMCMXCIX", result);
}
END_TEST

Suite * to_roman_suite_create(void)
{
    Suite *suite;
    suite = suite_create("convert arabic to roman");

    TCase *tcase;
    tcase = tcase_create("core");

    tcase_add_test(tcase, convert_1_to_I);
    tcase_add_test(tcase, convert_3_to_III);
    tcase_add_test(tcase, convert_4_to_IV);
    tcase_add_test(tcase, convert_5_to_V);
    tcase_add_test(tcase, convert_6_to_VI);
    tcase_add_test(tcase, convert_9_to_IX);
    tcase_add_test(tcase, convert_10_to_X);
    tcase_add_test(tcase, convert_40_to_XL);
    tcase_add_test(tcase, convert_50_to_L);
    tcase_add_test(tcase, convert_90_to_XC);
    tcase_add_test(tcase, convert_100_to_C);
    tcase_add_test(tcase, convert_400_to_CD);
    tcase_add_test(tcase, convert_500_to_D);
    tcase_add_test(tcase, convert_900_to_CM);
    tcase_add_test(tcase, convert_1000_to_M);
    tcase_add_test(tcase, convert_3999_to_MMMCMXCIX);

    suite_add_tcase(suite, tcase);
    return suite;
}

