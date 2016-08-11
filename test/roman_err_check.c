#include <check.h>
#include <stdio.h>
#include "roman_err_check.h"

#include "../src/roman.h"

START_TEST (nothing_yet)
{
    printf("todo: error handling tests\n");
}
END_TEST

Suite * roman_err_suite_create(void)
{
    Suite *suite;
    suite = suite_create("roman numeral converter errors");

    TCase *tcase;
    tcase = tcase_create("core");

    tcase_add_test(tcase, nothing_yet);

    suite_add_tcase(suite, tcase);
    return suite;
}

