#include <stddef.h>
#include <string.h>
#include "roman_err.h"

static RomanError roman_errors[] = {
    { ROMAN_E_SUCCESS },
    { ROMAN_E_NULL_BUFFER },
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
