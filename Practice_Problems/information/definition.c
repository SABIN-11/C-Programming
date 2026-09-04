//definition of the function encrypt declared in encryption.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "encryption.h"

#define KEY 3

void encrypt(char *plain_text){

    char *str = malloc(27 * sizeof(char));
    strcpy(str, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    int length = strlen(plain_text);

    for(int i = 0; i < length; i++){
        if(isalpha(plain_text[i])){
            plain_text[i] = str[((toupper(plain_text[i]) - 'A') + KEY) % 26];
        }
    }

}