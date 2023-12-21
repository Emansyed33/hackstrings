#include "string_utils.h"
#include <stdlib.h>
#include <string.h>

void replaceChar(char *s, char oldChar, char newChar) {
    for (; *s != '\0'; s++) {
        if (*s == oldChar) {
            *s = newChar;
        }
    }
}