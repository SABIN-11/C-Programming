// #include<stdio.h>
// int input(char[]);
// #define x 15
// int main(){
//     char str[x];
//     printf("Enter:");
//     input(str);
//     printf("%s",str);
//     return 0;
// }

// int input(char str[]){
//     int ch,i=0;
//     while ((ch=getchar())!='\n')
//     {
//         if(i<12){
//             str[i++]=ch;
//         }
//     }
//     str[i]='\0';
//     return i;
// }


#include<stdio.h>
#include<string.h>
int main(){
    char str1[12]="Hello World";
    char str2[12];
    strncpy(str2,str1,sizeof(str2));
    str2[sizeof(str2)]='\0';
    printf("%s",str2);
    return 0;
}


// #include<stdio.h>
// #include<string.h>
// int main(){
//     char ch[12];
//     puts(gets(ch));
//     return 0;
// }


//palindrome(string)


// #include<stdio.h>
// #include<string.h>
// #define x 12
// int main(){
//     char str1[x];
//     printf("Enter a string:");
//     fgets(str1,sizeof(str1),stdin);
//     //removing the newline character i.e "\n"
//     str1[strcspn(str1,"\n")]='\0';//terminating the array
//     char str2[x];
//     int len=strlen(str1);
//     int j=0;
//     for(int i=len-1;i>=0;i--){
//         str2[j]=str1[i];
//         j++;
//     }
//     str2[len]='\0';
//     if(strcmp(str1,str2)){
//         printf("%s is not palindrome",str1);
//     }
//     else
//     printf("%s is palindrome",str1);
// }


//concatenation

// #include<stdio.h>
// #include<string.h>
// #define k 20
// int main(){
//     char str1[k]="Hello ";
//     char str2[k]="World";
//     int x=strlen(str1)+strlen(str2);
//     strcat(str1,str2);
//     str1[x]='\0';
//     printf("%s",str1);
//     return 0;
// }

//reversing a string

// #include<stdio.h>
// #include<string.h>
// #define k 100
// int main(){
//     char str1[k];
//     printf("Enter a string:");
//     fgets(str1,sizeof(str1),stdin);
//     str1[strcspn(str1,"\n")]='\0';
//     int len=strlen(str1),j=0;
//     char str2[k];
//     for(int i=len-1;i>=0;i--){
//         str2[j]=str1[i];
//         j++;
//     }   
//     str2[j]='\0';
//     printf("%s",str2);
//     return 0;
// }

//counting vowels and consonants

// #include<stdio.h>
// #include<string.h>
// #include<ctype.h>
// #define k 100
// void count(int,char*,int*,int*);
// int main(){
//     char str[k];
//     int ctr_v=0,ctr_c=0;
//     printf("Enter a string:");
//     fgets(str,k,stdin);
//     str[strcspn(str,"\n")]='\0';
//     int len=strlen(str);
//     count(len,str,&ctr_v,&ctr_c);
//     printf("There are %d vowels in %s",ctr_v,str);
//     printf("\nThere are %d consonants in %s",ctr_c,str);
//     return 0;
// }

// void count(int len,char *ptr,int *v,int *c){
//     int j=0;
//     char ch;
//     for(int i=len-1;i>=0;i--){
//         ch=tolower(*(ptr+j));
//         if(isalpha(*(ptr+j)))
//         {
//         switch (ch)
//         {
//         case 'a':
//         case 'e':
//         case 'i':
//         case 'o':
//         case 'u':
//         (*v)++;
//         break;
//         default:
//         (*c)++;
//         break;
//         }
//         j++;
//         }
//     }
// }

//counting the words in a string


// #include<stdio.h>
// #include<string.h>
// #define n 100
// int main()
// {
//     char str[n];
//     fgets(str,n,stdin);
//     str[strcspn(str,"\n")]='\0';
    
//     int ctr=1;
//     for(int i=0;str[i]!='\0';i++){
//         if(str[i]==' ')
//         ctr++;
//     }
//     printf("There are %d words.",ctr);
    
//     return 0;
// }


//slicing a string from index n to m


// #include<stdio.h>
// #include<string.h>
// char* slice(char*,int,int);
// #define x 20
// char str2[x];
// int main(){
//     char str1[x];
//     printf("Enter a string:");
//     fgets(str1,x,stdin);
//     str1[strcspn(str1,"\n")]='\0';
//     char *ptr=slice(str1,3,6);
//     printf("%s",ptr);
//     return 0;
// }

// char* slice(char *p,int n,int m){
//     int j=0;
//     for(int i=n;i<=m;i++){
//         str2[j]=*(p+i);
//         j++;
//     }
//     str2[j]='\0';
//     return str2;
// }


//check if a given character is present in a string or not


// #include<stdio.h>
// #include<string.h>
// #include<stdbool.h>
// bool check(char[],char);
// #define n 100
// int main(){
//     char str[n]="HELLOWORLD";
//     printf("Enter a character you want to check:");
//     // char ch=getchar();
//     if(check(str,getchar()))
//     printf("YES");
//     else
//     printf("NO");
//     return 0;
// }
// bool check(char str[],char ch){
//     for(int i=0;str[i]!='\0';i++){
//         if(str[i]==ch)
//         return 1;
//     }
// }