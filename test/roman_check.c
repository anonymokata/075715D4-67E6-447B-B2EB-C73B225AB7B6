#include <stdio.h>
#include <check.h>
#include "roman_check.h"

START_TEST (test_check)
{
    printf("testing my unit testing framework\n");
}
END_TEST

Suite * roman_suite_create(void)
{
    Suite *suite;
    suite = suite_create("roman");

    TCase *tcase;
    tcase = tcase_create("core");

    tcase_add_test(tcase, test_check);

    suite_add_tcase(suite, tcase);
    return suite;
}

