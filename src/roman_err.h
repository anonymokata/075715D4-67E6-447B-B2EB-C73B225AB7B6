#ifndef ROMAN_ERR_H
#define ROMAN_ERR_H

typedef struct {
    int code;
} RomanError;

enum {
    ROMAN_E_NULL_BUFFER,
    ROMAN_E_UNKNOWN
};

extern RomanError *roman_error(int code);

#endif /* ROMAN_ERR_H */
