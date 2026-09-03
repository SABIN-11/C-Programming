//checking if second string is present in first or not

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAX_SIZE 30

bool checkPresent(char str1[MAX_SIZE], char str2[MAX_SIZE]){

    int length=strlen(str1);

    if(strcspn(str1,str2) != length)    //returns the number of characters before finding the matchable ones
    return true;

    else
    return false;

    // if(strstr(str1,str2))   //returns the pointer to the substring if found otherwise returns null
    // return true;

    // else
    // return false;

}

int main(){

    char string1[MAX_SIZE], string2[MAX_SIZE];

    printf("Enter two strings:");
    scanf("%s%s",string1,string2);

    if(checkPresent(string1,string2))
    printf("Present!");

    else
    printf("Not Present!");

    return 0;
}