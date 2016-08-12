#include <stddef.h>
#include <string.h>
#include "rome_calc_err.h"

static RomeCalcError rome_calc_errors[] = {
    { ROME_CALC_E_SUCCESS, "success" },
    { ROME_CALC_E_NULL_BUFFER, "output buffer is null" },
    { ROME_CALC_E_INPUT_NULL, "a null pointer operand was passed in" },
    { ROME_CALC_E_BUFFER_NOT_EMPTY, "output buffer not empty" },
    { ROME_CALC_E_EMPTY_STRING, "an empty string operand was passed in" },
    { ROME_CALC_E_TO_ROMAN, "conversion of arabic to roman failed" },
    { ROME_CALC_E_TO_ARABIC, "conversion of roman to arabic failed" },
    { ROME_CALC_E_UNKNOWN, "unknown" }
};

void rome_calc_error(RomeCalcError *out, int code)
{
    if (out == NULL) {
        return;
    }

    RomeCalcError *next;
    for (next = rome_calc_errors; next->code != ROME_CALC_E_UNKNOWN; next++) {
        if (code == next->code) {
            break;
        }
    }

    memcpy(out, next, sizeof(RomeCalcError));
}
