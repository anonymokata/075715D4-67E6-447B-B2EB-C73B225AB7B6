#include <check.h>
#include "rome_calc_check.h"

#include "../src/rome_calc.h"

START_TEST (add_I_to_I)
{
    char result[3] = {0};
    rome_add("I", "I", result);
    ck_assert_str_eq("II", result);
}
END_TEST

Suite * rome_calc_suite_create(void)
{
    Suite *suite;
    suite = suite_create("do roman arithmetic");

    TCase *tcase_addition;
    tcase_addition = tcase_create("addition");

    tcase_add_test(tcase_addition, add_I_to_I);

    suite_add_tcase(suite, tcase_addition);

    /*
    TCase *tcase_subtraction;
    tcase_subtraction = tcase_create("subtraction");

    tcase_add_test(tcase_subtraction, subtract_I_from_II);

    suite_add_tcase(suite, tcase_subtraction);
    */

    return suite;
}

