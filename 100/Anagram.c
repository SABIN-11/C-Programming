// checking whether two strings are anagrams or not

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

void length(char[],char[],int*,int*);
bool anagram(char[],char[],int,int,int,int);

 
#define Max_Len 50    //macro defining

int main(){

    char str1[Max_Len]="silent";
    char str2[Max_Len]="listen";

    int l1=strlen(str1);
    int l2=strlen(str2);

    int len1=0,len2=0;
    length(str1,str2,&len1,&len2);  //function calling

    if(anagram(str1,str2,l1,l2,len1,len2))    //checking it true or false
    printf("%s and %s are anagrams",str1,str2);
    
    else
    printf("%s and %s are not anagrams",str1,str2);

    return 0;

}       

bool anagram(char str1[],char str2[],int l1,int l2,int len1,int len2){

    int conditionCtr=0; //initializing condition counter as 0
    int stringCtr=0;   //initializing the string counter as 0

    if(len1==len2)  //first condition
    conditionCtr++;
    else
    return false;   //returning false

    for(int i=0;i<l1;i++){

        for(int j=0;j<l2;j++){

            if(!(isspace(str1[i])) && !(isspace(str2[j]))){

            if(str1[i]==str2[j]){

            stringCtr++;
            break;

            }
        }
            
        }
    }    

    if(stringCtr==len1) //second condition
    conditionCtr++;
    
    if(conditionCtr==2)
    return true;   //retutning true
    else
    return false;   //returning false

}

void length(char str1[],char str2[],int *len1,int *len2){

    for(int i=0;str1[i]!='\0';i++){
        
        if(!(isspace(str1[i])))
        (*len1)++;
        else
        continue;   //skip if its space

    }

     for(int i=0;str2[i]!='\0';i++){
        
        if(!(isspace(str2[i])))
        (*len2)++;
        else
        continue;   //skip if its space
        
    }
}

//same code

// #include<stdio.h>
// #include<string.h>
// #include<stdbool.h>
// #include<ctype.h>

// #define MAX_LEN 50 // macro defining

// bool anagram(char[], char[]);

// int main() {

//     char str1[MAX_LEN] = "silent";
//     char str2[MAX_LEN] = "listen";

//     if (anagram(str1, str2)) // checking it true or false
//         printf("%s and %s are anagrams\n", str1, str2);
//     else
//         printf("%s and %s are not anagrams\n", str1, str2);

//     return 0;
// }

// bool anagram(char str1[], char str2[]) {

//     int count1[256] = {0}, count2[256] = {0}; // frequency arrays
//     int i;

//     // Count frequency of each character in str1
//     for (i = 0; str1[i] && str2[i]; i++) {

//         if (!isspace(str1[i])) {

//             count1[tolower(str1[i])]++; // Convert to lowercase for case insensitivity

//         }
//         if (!isspace(str2[i])) {

//             count2[tolower(str2[i])]++; // Convert to lowercase for case insensitivity
            
//         }

//     }

//     // If both strings are of different length
//     if (str1[i] != '\0' || str2[i] != '\0') {
//         return false;
//     }

//     // Compare frequency arrays
//     for (i = 0; i < 256; i++) {

//         if (count1[i] != count2[i]) {
//             return false;
//         }

//     }

//     return true;
// }