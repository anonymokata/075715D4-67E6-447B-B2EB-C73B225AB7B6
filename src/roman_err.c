#include <stddef.h>
#include <string.h>
#include "roman_err.h"

static RomanError roman_errors[] = {
    { ROMAN_E_SUCCESS },
    { ROMAN_E_NULL_BUFFER },
    { ROMAN_E_INPUT_NULL },
    { ROMAN_E_BUFFER_NOT_EMPTY },
    { ROMAN_E_ARABIC_LT_ONE },
    { ROMAN_E_ARABIC_GT_3999 },
    { ROMAN_E_DOUBLE_REPEAT },
    { ROMAN_E_INVALID_NUMERAL },
    { ROMAN_E_INVALID_ORDER },
    { ROMAN_E_INVALID_REPEAT },
    { ROMAN_E_QUADS },
    { ROMAN_E_EMPTY_STRING },
    { ROMAN_E_UNKNOWN }
};

void roman_error(RomanError **out, int code)
{
    if (*out == NULL) {
        return;
    }

    RomanError *next;
    for (next = roman_errors; next->code != ROMAN_E_UNKNOWN; next++) {
        if (code == next->code) {
            break;
        }
    }

    memcpy(*out, next, sizeof(RomanError));
}
