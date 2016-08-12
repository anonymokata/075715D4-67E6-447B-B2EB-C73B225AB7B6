#ifndef ROME_CALC_H
#define ROME_CALC_H

#include "rome_calc_err.h"

extern void rome_add(char const *a, char const *b, char *buffer,
        RomeCalcError *err);

extern void rome_subtract(char const *a, char const *b, char *buffer,
        RomeCalcError *err);

#endif /* ROME_CALC_H */
