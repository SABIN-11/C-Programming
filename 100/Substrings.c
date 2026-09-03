//Converting all lowercases vowels to uppercase in a string

// #include<stdio.h>
// #include<string.h>
// #include<ctype.h>
// #define n 100
// char* convert(char[]);
// int main(){
//     char str[n];
//     printf("Enter a string:");
//     fgets(str,n,stdin);
//     str[strcspn(str,"\n")]='\0';
//     char *str2=convert(str);
//     printf("%s",str2);
//     return 0;
// }

// char* convert(char str[]){
//     for(int i=0;str[i]!='\0';i++){
//     if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
//     str[i]=toupper(str[i]);
//     }
//     return str;
// }

//printing highest frequency character in a string

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
void frequency(char[]);
#define n 100
int main(){
    char str[n];

    printf("Enter a string:");
    fgets(str,n,stdin);

    str[strcspn(str,"\n")]='\0';

    // int x=frequency(str);
    frequency(str);

    return 0;
}
void frequency(char str[]){
    int freq[n]={0};
    bool f[n];

    for(int i=0;str[i]!='\0';i++){
    freq[i]=1;
    }

    for(int i=0;i<n;i++){
        f[i]=true;   //inisializing true to all index for the length of the string
    }

    for(int i=0;str[i]!='\0';i++){

        if(f[i]==true)
        {

        for(int j=i+1;str[j]!='\0';j++){
            if(str[i]==str[j]){

                freq[i]++;
                f[j]=false;

            }
        }
        }
    }

    int maxFreq=0;
    // int x=0;
    // for(int i=0;str[i]!='\0';i++){
    //     if(f[i]==true){
    //         printf("%c occurs %d times\n",str[i],freq[i]);
    //     }
    // }

    for(int i=0;str[i]!='\0';i++){
        if(f[i]==true){
            if(maxFreq<freq[i]){
                maxFreq=freq[i];
                // x=i;
            }
        }
    }

    // printf("Highest frequency character is %c\n",str[x]);
    
    printf("Characters with the highest frequency:\n");
    for (int i = 0; str[i] != '\0'; i++) {
        if (f[i] == true && freq[i] == maxFreq) {
            printf("'%c' occurs %d times\n", str[i], freq[i]);
        }
    }
}


//removing the blank space in a string

// #include<stdio.h>
// #include<string.h>
// #define n 20
// char* blank(char[]);
// int main(){
//     char str[n];

//     printf("Enter a string with a blank space in between:");
//     fgets(str,n,stdin);

//     printf("\nBefore removing the blank space:");
//     puts(str);

//     str[strcspn(str,"\n")]='\0';//remove newline character

//     // char *ptr=blank(str);

//     printf("After removing the blank space:");
//     puts(ptr);

//     printf("\n");

//     return 0;
// }

// char* blank(char str[]){

//     int j;
//     int len=strlen(str);

//     for(int i=0;i<len;i++){

//         if(str[i]==' '){

//             for(j=i;j<len;j++){

//                 str[j]=str[j+1];

//             }
//             len--;
//             i--;
//         }
//     }

//     return str;
// }



//replacing substrings


//input:"hello world! hello everyone"
//output:hi world! hi everyone
//problem:replace hello with hi

// #include<stdio.h>
// #include<string.h>

// #define n 50    //macro define
// void replace(char[]);   //function declaration

// int main(){

//     char str1[n]="hello world! hello everyone"; //input

//     replace(str1);  //calling function  
    
//     return 0;

// }

// void replace(char str1[]){  //function definition

//     char str2[n]="";    //initialising null 
//     int len=strlen(str1);   //length of str1
//     int i,j=0;  //i for str1 :: j for str2

//     for( i=0;i<len;i++){

//         if(strncmp(&str1[i],"hello",5)==0){    //checking if word is hello upto 5 characters

//             strcpy(&str2[j],"hi");      
//             j+=2;   //incrementing j by 2 : length of hi is 2
//             i+=4;   //incrementing i by 4 : length of hello is 5 and i will be incremented at the end

//         }
//         else{
            
//             str2[j++]=str1[i];     //if word is not hello, assining other words to str2
            
//         }

//     }

//     str2[j]='\0';   //null terminating
//     printf("%s",str2);

// }


//capitalizing the first character of every word


#include<stdio.h>
#include<string.h>
#include<ctype.h>

void capitalize(char[]);
#define n 50   //macro defining

int main(){

    char str[n]; 

    //input
    printf("Enter a sentence:");
    fgets(str,n,stdin);
    str[strcspn(str,"\n")]='\0'; //removing new line character

    capitalize(str);    //calling
    printf("%s",str);

    return 0;

}

void capitalize(char str[]){

    int i,j=0;

    for(i=0;str[i]!='\0';i++){  //until it reaches the null terminator

        if(j==0){
            str[i]=toupper(str[i]);
            j++;
        }

        //to find the next word
        if(str[i]==' '){
            j=0;    
        }

    }

}