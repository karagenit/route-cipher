#include <stdlib.h>
#include <stdio.h>

// Prepares string for cipher
char* prepString(char *str, int targetLength) {
    // Allocate memory for cleaned string
    char *stripStr = calloc(targetLength, sizeof(char)); //FREEME
    int stripIndex = 0;
    char c;
    // Copy only letters from string into new string
    for (int i = 0; (c = str[i]) != 0; i++) {
        // Convert lower case to upper case
        if (c >= 'a' && c <= 'z') {
            c = c - 'a' + 'A';
        }
        // Save only text characters
        if (c >= 'A' & c <= 'Z') {
            stripStr[stripIndex] = c;
            stripIndex++;
        }
    }
    // Pad remaining space with Xes
    for (int i = stripIndex; i < targetLength; i++) {
        stripStr[i] = 'X';
    }
}

char* cwRoute(char *str, int cols, int rows) {
    char *string = prepString(str, cols * rows);
}

void main() {
    prepString("Hello!", 6);
}

