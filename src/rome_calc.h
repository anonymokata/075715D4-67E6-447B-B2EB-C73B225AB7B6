#ifndef ROME_CALC_H
#define ROME_CALC_H

#include "rome_calc_err.h"

extern void rome_add(char const *a, char const *b, char *result,
        RomeCalcError *err);

extern void rome_subtract(char const *a, char const *b, char *result,
        RomeCalcError *err);

#endif /* ROME_CALC_H */
