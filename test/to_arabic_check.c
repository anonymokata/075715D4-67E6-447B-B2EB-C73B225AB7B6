#include <check.h>
#include "to_arabic_check.h"

#include "../src/roman.h"

START_TEST (convert_I_to_1)
{
    int result = to_arabic("I");
    ck_assert_int_eq(1, result); 
}
END_TEST

START_TEST (convert_III_to_3)
{
    int result = to_arabic("III");
    ck_assert_int_eq(3, result); 
}
END_TEST

START_TEST (convert_IV_to_4)
{
    int result = to_arabic("IV");
    ck_assert_int_eq(4, result); 
}
END_TEST

START_TEST (convert_V_to_5)
{
    int result = to_arabic("V");
    ck_assert_int_eq(5, result); 
}
END_TEST

START_TEST (convert_VI_to_6)
{
    int result = to_arabic("VI");
    ck_assert_int_eq(6, result);
}
END_TEST

START_TEST (convert_MMMCMXCIX_to_3999)
{
    int result = to_arabic("MMMCMXCIX");
    ck_assert_int_eq(3999, result);
}
END_TEST

Suite * to_arabic_suite_create(void)
{
    Suite *suite;
    suite = suite_create("convert roman to arabic");

    TCase *tcase;
    tcase = tcase_create("core");

    tcase_add_test(tcase, convert_I_to_1);
    tcase_add_test(tcase, convert_III_to_3);
    tcase_add_test(tcase, convert_IV_to_4);
    tcase_add_test(tcase, convert_V_to_5);
    tcase_add_test(tcase, convert_VI_to_6);
    tcase_add_test(tcase, convert_MMMCMXCIX_to_3999);

    suite_add_tcase(suite, tcase);
    return suite;
}

