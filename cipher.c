#include <stdlib.h>
#include <stdio.h>

// Removes spaces etc, makes all caps, pads with Xes
char* prepString(char *str, int targetLength) {
    // Count # of letters in str
    int stripSize = 0;
    char c;
    for (int i = 0; (c = str[i]) != 0; i++) {
        if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
            stripSize++;
        }
    }
    // Allocate string for them only
    char *stripStr = calloc(stripSize, sizeof(char)); //FREEME
    int stripIndex = 0;
    // Copy only letters from string into new string
    for (int i = 0; (c = str[i]) != 0; i++) {
        if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
            stripStr[stripIndex] = c;
            stripIndex++;
            putchar(c);
        }
    }
    // Convert text into all caps
}

char* cwRoute(char *str, int cols, int rows) {
    char *string = prepString(str, cols * rows);
}

void main() {
    prepString("Hello!", 6);
}

