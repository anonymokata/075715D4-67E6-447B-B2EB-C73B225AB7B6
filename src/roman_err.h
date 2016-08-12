#ifndef ROMAN_ERR_H
#define ROMAN_ERR_H

typedef struct {
    int code;
} RomanError;

enum {
    ROMAN_E_SUCCESS,
    ROMAN_E_NULL_BUFFER,
    ROMAN_E_ARABIC_LT_ONE,
    ROMAN_E_ARABIC_GT_3999,
    ROMAN_E_UNKNOWN
};

extern void roman_error(RomanError **out, int code);

#endif /* ROMAN_ERR_H */
