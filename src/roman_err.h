#ifndef ROMAN_ERR_H
#define ROMAN_ERR_H

typedef struct {
    int code;
} RomanError;

enum {
    ROMAN_E_NULL_BUFFER 
};

extern RomanError roman_errors[];

#endif /* ROMAN_ERR_H */
