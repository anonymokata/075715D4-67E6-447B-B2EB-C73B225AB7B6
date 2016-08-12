#include <stddef.h>
#include <string.h>
#include "rome_calc_err.h"

static RomeCalcError rome_calc_errors[] = {
    { ROME_CALC_E_SUCCESS },
    { ROME_CALC_E_NULL_BUFFER },
    { ROME_CALC_E_INPUT_NULL },
    { ROME_CALC_E_BUFFER_NOT_EMPTY },
    { ROME_CALC_E_EMPTY_STRING },
    { ROME_CALC_E_UNKNOWN }
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
