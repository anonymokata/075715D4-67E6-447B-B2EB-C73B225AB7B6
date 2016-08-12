#include <stdlib.h>
#include <check.h>

#include "to_roman_check.h"
#include "to_arabic_check.h"
#include "roman_err_check.h"
#include "rome_calc_check.h"
#include "rome_calc_err_check.h"

void run_suite(Suite *suite, int *failures)
{
    SRunner *srunner;
    srunner = srunner_create(suite);

    srunner_run_all(srunner, CK_NORMAL);

    *failures += srunner_ntests_failed(srunner);
    srunner_free(srunner);
}

int main(void)
{
    int failures = 0;

    run_suite(to_roman_suite_create(), &failures);
    run_suite(to_arabic_suite_create(), &failures);
    run_suite(roman_err_suite_create(), &failures);
    run_suite(rome_calc_suite_create(), &failures);
    run_suite(rome_calc_err_suite_create(), &failures);

    return (failures == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
