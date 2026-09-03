//take a sentence as an input and print every words of the sentence in new line

#include<stdio.h>
#include<string.h>

#define MAX_SIZE 200
#define space ' '

void printInNewLine(char sentence[MAX_SIZE]){

    int length=strlen(sentence);    //calculating the length of the sentence including the spaces

    for(int i = 0; i < length; i++){

        printf("%c",sentence[i]);

        if(sentence[i] == space)    //printing newline character when space is encountered
        printf("\n");

    }

}

int main(){

    char sentence[MAX_SIZE];

    printf("Enter a sentence:");
    fgets(sentence, sizeof(sentence), stdin); //taking input from keyboard
    sentence[strcspn(sentence,"\n")]='\0'; //assingning null terminator in the end

    printInNewLine(sentence);

    return 0;
}