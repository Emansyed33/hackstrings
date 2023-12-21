#include <stdio.h>
#include "string_utils.h"

void printSplitArray(char **split, int size, int n) {
    for (int i = 0; i < size; ++i) {
        printf("\"%s\"", split[i]);
        if (i < size - 1) printf(", ");
        free(split[i]); // Free each string after use
    }
    free(split); // Free the array of strings
    printf("\n");
}

int main() {
    char str[] = "This is a test string for replaceChar function";
    char *strCopy;
    char **split;

    // Test replaceChar
    printf("Original string: %s\n", str);
    replaceChar(str, 's', 'z');
    printf("Replaced 's' with 'z': %s\n", str);

    // Test replaceCharCopy
    strCopy = replaceCharCopy(str, 'z', 's');
    printf("Replaced 'z' with 's' copy: %s\n", strCopy);
    free(strCopy); // Free the string after use

    // Reset str for next test
    strcpy(str, "This is a test string for removeChar function");

    // Test removeChar
    printf("Original string: %s\n", str);
    removeChar(str, 't');
    printf("Removed 't': %s\n", str);

    // Test removeCharCopy
    strCopy = removeCharCopy(str, 's');
    printf("Removed 's' copy: %s\n", strCopy);
    free(strCopy); // Free the string after use

    // Test lengthSplit
    const char *longStr = "Hello World, how are you?";
    int n = 3;
    int numChunks = (strlen(longStr) + n - 1) / n; // Calculate the number of chunks
    split = lengthSplit(longStr, n);
    printf("Splitting \"%s\" into chunks of %d: ", longStr, n);
    printSplitArray(split, numChunks, n);

    return 0;
}
