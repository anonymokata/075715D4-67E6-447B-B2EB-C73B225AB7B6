#include <stddef.h>
#include <string.h>
#include "roman_err.h"

static RomanError roman_errors[] = {
    { ROMAN_E_SUCCESS, "success" },
    { ROMAN_E_NULL_BUFFER, "output buffer is null" },
    { ROMAN_E_INPUT_NULL, "roman string pointer is null" },
    { ROMAN_E_BUFFER_NOT_EMPTY, "output buffer is not empty" },
    { ROMAN_E_ARABIC_LT_ONE, "arabic input must be greater than zero" },
    { ROMAN_E_ARABIC_GT_3999, "arabic input must be less than 4000" },
    { ROMAN_E_INVALID_NUMERAL, "invalid numeral" },
    { ROMAN_E_INVALID_ORDER, "invalid roman numeral ordering" },
    { ROMAN_E_INVALID_REPEAT, "invalid numeral repetitions"},
    { ROMAN_E_QUADS, "numeral repeated four times" },
    { ROMAN_E_EMPTY_STRING, "input string was empty" },
    { ROMAN_E_UNKNOWN, "unknown" }
};

void roman_error(RomanError *out, int code)
{
    if (out == NULL) {
        return;
    }

    RomanError *next;
    for (next = roman_errors; next->code != ROMAN_E_UNKNOWN; next++) {
        if (code == next->code) {
            break;
        }
    }

    memcpy(out, next, sizeof(RomanError));
}
