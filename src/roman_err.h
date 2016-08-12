#ifndef ROMAN_ERR_H
#define ROMAN_ERR_H

typedef struct {
    int code;
} RomanError;

enum {
    ROMAN_E_SUCCESS,
    ROMAN_E_NULL_BUFFER,
    ROMAN_E_INPUT_NULL,
    ROMAN_E_BUFFER_NOT_EMPTY,
    ROMAN_E_ARABIC_LT_ONE,
    ROMAN_E_ARABIC_GT_3999,
    ROMAN_E_DOUBLE_REPEAT,
    ROMAN_E_INVALID_NUMERAL,
    ROMAN_E_INVALID_ORDER,
    ROMAN_E_INVALID_REPEAT,
    ROMAN_E_UNKNOWN
};

extern void roman_error(RomanError **out, int code);

#endif /* ROMAN_ERR_H */
