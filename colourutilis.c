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
char *replaceCharCopy(const char *s, char oldChar, char newChar) {
    char *newStr = strdup(s);
    if (!newStr) return NULL;
    replaceChar(newStr, oldChar, newChar);
    return newStr;
}
