#include <stdlib.h>
#include <stdio.h>

// Prepares string for cipher
char* prepString(char *str, int targetLength) {
    // Allocate memory for cleaned string
    char *stripStr = calloc(targetLength, sizeof(char));
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
    for (int boxCols = cols, boxRows = rows; boxCols > 0 && boxRows > 0; 
            boxCols -= 2, boxRows -= 2) {
        cipher[cipherIndex] = string[stringIndex];
        cipherIndex += 1;
        for (int i = 0; i < boxRows - 1; i++) {
            stringIndex += cols;
            cipher[cipherIndex] = string[stringIndex];
            cipherIndex += 1;
        }
        for (int i = 0; i < boxCols - 1; i++) {
            stringIndex -= 1;
            cipher[cipherIndex] = string[stringIndex];
            cipherIndex += 1;
        }
        for (int i = 0; i < boxRows - 1; i++) {
            stringIndex -= cols;
            cipher[cipherIndex] = string[stringIndex];
            cipherIndex += 1;
        }
        for (int i = 0; i < boxCols - 2; i++) {
            stringIndex += 1;
            cipher[cipherIndex] = string[stringIndex];
            cipherIndex += 1;
        }
        stringIndex += cols;
    }

    free(string);
    return cipher;
}

void route(char *str, int cols, int rows) { // TODO: cw vs ccw
    char *text = cwRoute(str, cols, rows);
    printf("%.*s\n", cols * rows, text);
    free(text);
}

void main() {
    route("We are discovered, flee at once", 9, 3);
    route("For lunch let's have peanut-butter and bologna sandwiches", 4, 12);
    route("I've even witnessed a grown man satisfy a camel", 9, 5);
}

