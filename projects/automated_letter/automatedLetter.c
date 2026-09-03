//change the values of {{name}}, {{item}} and {{outlet}} from the letter.txt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

typedef struct automation{
    char name[MAX_LENGTH];
    char item[MAX_LENGTH];
    char outlet[MAX_LENGTH];
    char option[3][MAX_LENGTH];
}automate;

void automate_Letter(automate *letter){

    FILE *fp = NULL;
    fp = fopen("letter.txt", "r");
    if(fp == NULL){
        perror("Could not open file\n");
        exit(EXIT_FAILURE);
    }

    FILE *atL = NULL;
    atL = fopen("newLetter.txt", "w");
    if(atL == NULL){
        perror("Could not open file\n");
        exit(EXIT_FAILURE);
    }

    char string[MAX_LENGTH];
    char substring[MAX_LENGTH];

    while(fscanf(fp, "%s", string) != EOF){

        if(strstr(string,".")){
            for(int i = 0; i < strlen(string) - 1; i++){
                substring[i] = string[i];
            }
        }
        else{
            strcpy(substring, string);
        }

        if(strcmp(substring, letter->option[0]) == 0){
            fprintf(atL, "{{%s}} ",letter->name);
        }
        else if(strcmp(substring, letter->option[1]) == 0){
            fprintf(atL, "{{%s}} ",letter->item);
        }
        else if(strcmp(substring, letter->option[2]) == 0){
            fprintf(atL, "{{%s}} ",letter->outlet);
        }
        else{
            fprintf(atL, "%s ", string);
        }

    }


    fclose(fp);
    fclose(atL);
}

int main() {

    automate letter = {{0}, {0}, {0}, {"{{name}}", "{{item}}", "{{outlet}}"}};   //null initializing

    //user input
    printf("Enter your name:");
    fgets(letter.name, MAX_LENGTH, stdin);
    letter.name[strcspn(letter.name,"\n")] = '\0';

    printf("\nEnter the item:");
    fgets(letter.item, MAX_LENGTH, stdin);
    letter.item[strcspn(letter.item,"\n")] = '\0';

    printf("\nEnter the outlet:");
    fgets(letter.outlet, MAX_LENGTH, stdin);
    letter.outlet[strcspn(letter.outlet,"\n")] = '\0';

    automate_Letter(&letter);
    
    return 0;
}