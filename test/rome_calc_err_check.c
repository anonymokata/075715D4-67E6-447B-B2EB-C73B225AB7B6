#include <check.h>
#include <stdio.h>
#include "rome_calc_err_check.h"

#include "../src/rome_calc.h"

START_TEST (begin)
{
    printf("a new test dawns\n");
}
END_TEST

Suite * rome_calc_err_suite_create(void)
{
    Suite *suite;
    suite = suite_create("roman numeral calculator errors");

    TCase *tcase;
    tcase = tcase_create("core");

    tcase_add_test(tcase, begin);

    suite_add_tcase(suite, tcase);
    return suite;
}

