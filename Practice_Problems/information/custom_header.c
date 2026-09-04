//we will include custom header file in this file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encryption.h"

#define MAX_LENGTH 100

int main() {

    char *plain_text = malloc(MAX_LENGTH * sizeof(char));   //step 1: allocate memory for the plain_text given by the user
    //step 2: get input from standard input i.e keyboard
    printf("Enter some text:\n");
    fgets(plain_text, MAX_LENGTH, stdin);
    //plain_text[strcspn(plain_text, "\n")] = '\0';
    plain_text[strlen(plain_text) - 1] = '\0';
    encrypt(plain_text);

    printf("%s", plain_text);
    return 0;
}