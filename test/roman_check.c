#include <stdio.h>
#include <check.h>
#include "roman_check.h"

#include "../src/roman.h"

START_TEST (convert_1_to_I)
{
    char *result = arabic_to_roman(1);
    ck_assert_str_eq("I", result); 
}
END_TEST

START_TEST (convert_5_to_V)
{
    char *result = arabic_to_roman(5);
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
    tcase_add_test(tcase, convert_5_to_V);

    suite_add_tcase(suite, tcase);
    return suite;
}

