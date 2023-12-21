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
void removeChar(char *s, char c) {
    char *prune = s;
    while (*s) {
        if (*s != c) {
            *prune++ = *s;
        }
        s++;
    }
    *prune = '\0';
}

char *removeCharCopy(const char *s, char c) {
    char *newStr = (char *)malloc(strlen(s) + 1); // +1 for null terminator
    if (!newStr) return NULL;

    char *temp = newStr;
    while (*s) {
        if (*s != c) {
            *temp++ = *s;
        }
        s++;
    }
    *temp = '\0';
    return newStr;
}
char *removeCharCopy(const char *s, char c) {
    char *newStr = (char *)malloc(strlen(s) + 1); // +1 for null terminator
    if (!newStr) return NULL;

    char *temp = newStr;
    while (*s) {
        if (*s != c) {
            *temp++ = *s;
        }
        s++;
    }
    *temp = '\0';
    return newStr;
}

char **lengthSplit(const char *s, int n) {
    int len = strlen(s);
    int numStrings = (len + n - 1) / n; // Calculate the number of chunks
    char **splitArray = (char **)malloc(numStrings * sizeof(char *));

    if (!splitArray) return NULL;

    for (int i = 0; i < numStrings; ++i) {
        splitArray[i] = (char *)malloc(n + 1); // +1 for null terminator
        if (!splitArray[i]) {
            // Free previously allocated memory if error occurs
            while (i--) free(splitArray[i]);
            free(splitArray);
            return NULL;
        }
        strncpy(splitArray[i], s + i * n, n);
        splitArray[i][n] = '\0'; // Ensure each