#include "roman_err.h"

RomanError roman_errors[] = {
    { ROMAN_E_NULL_BUFFER },
    { ROMAN_E_UNKNOWN }
};

RomanError *roman_error(int code)
{
    RomanError *next;
    for (next = roman_errors; next->code != ROMAN_E_UNKNOWN; next++) {
        if (code == next->code) {
            break;
        }
    }
    return next;
}
