//encryption using Ceaser Cipher method
// C = E(p, k) = (p + k) MOD 26
//p is the associated value with the character
//k is the key i.e 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY 3

int main() {

    char *string = malloc(50 * sizeof(char));
    strcpy(string, "zebra");

    char *str = malloc(27 * sizeof(char));
    strcpy(str, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    int length = strlen(string);
    char s[4];
    int k = 0;

    printf("Before encryption: %s",string);

    for(int i = 0; i < length; i++){
        if(isalpha(string[i])){
            string[i] = str[((toupper(string[i]) - 'A') + KEY) % 26];
        }
    }

    printf("\nAfter encryption: %s",string);
    return 0;
}