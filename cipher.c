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

    return stripStr;
}

char* cwRoute(char *str, int cols, int rows) {
    char *string = prepString(str, cols * rows);
    char *cipher = calloc(cols * rows, sizeof(char));

    int cipherIndex = 0;
    int stringIndex = cols - 1;
    // Iterates over each 'box'
    for (int ci = cols, cr = rows; ci > 0 && cr > 0; ci -= 2, cr -= 2) {
        cipher[cipherIndex] = string[stringIndex];
        cipherIndex += 1;
        for (int i = 0; i < rows - 1; i++) {
            stringIndex += cols;
            cipher[cipherIndex] = string[stringIndex];
            cipherIndex += 1;
        }
        for (int i = 0; i < cols - 1; i++) {
            stringIndex -= 1;
            cipher[cipherIndex] = string[stringIndex];
            cipherIndex += 1;
        }
        for (int i = 0; i < rows - 1; i++) {
            stringIndex -= cols;
            cipher[cipherIndex] = string[stringIndex];
            cipherIndex += 1;
        }
        for (int i = 0; i < cols - 2; i++) {
            stringIndex += 1;
            cipher[cipherIndex] = string[stringIndex];
            cipherIndex += 1;
        }
        stringIndex += cols;
    }

    free(string);
    return cipher;
}

void main() {
    char *text = cwRoute("Hello!", 3, 2);
    printf("%.*s", 6, text);
    free(text);
}

