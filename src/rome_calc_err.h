#ifndef ROME_CALC_ERR_H
#define ROME_CALC_ERR_H

typedef struct {
    int code;
    char *message;
} RomeCalcError;

enum {
    ROME_CALC_E_SUCCESS,
    ROME_CALC_E_NULL_BUFFER,
    ROME_CALC_E_INPUT_NULL,
    ROME_CALC_E_BUFFER_NOT_EMPTY,
    ROME_CALC_E_EMPTY_STRING,
    ROME_CALC_E_TO_ROMAN,
    ROME_CALC_E_TO_ARABIC,
    ROME_CALC_E_UNKNOWN
};

extern void rome_calc_error(RomeCalcError *out, int code);

#endif /* ROME_CALC_ERR_H */
