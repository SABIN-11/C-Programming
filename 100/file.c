// #include<stdio.h>
// int main(){

//     FILE *fptr;

//     fptr=fopen("test.txt","r");

//     if(fptr==NULL)
//     printf("Error");

//     fclose(fptr);

//     return 0;
// }

// #include<stdio.h>

// int main() {
//     FILE *fptr;
//     char ch;

//     // Open file in read mode
//     fptr = fopen("test.txt", "r");
//     if (fptr == NULL) {
//         printf("Error opening file!\n");
//         return 1; // Return non-zero to indicate error
//     }

//     // Read a single character from file
//     if (fscanf(fptr, "%c", &ch) != 1) {
//         printf("Error reading from file!\n");
//         fclose(fptr); // Close file before returning
//         return 1; // Return non-zero to indicate error
//     }

//     // Print the character read
//     printf("%c\n", ch);

//     // Close the file
//     fclose(fptr);

//     return 0;
// }

// #include<stdio.h>
// int main(){

//     FILE *fptr;
//     char ch;
    
//     fptr=fopen("test.txt","r");

//     while(fscanf(fptr,"%c",&ch)!=EOF)
//     printf("%c",ch);
    
//     fclose(fptr);

//     return 0;
// }


//write a program to write the odd numbers from 1 to n in a file

// #include<stdio.h>
// int main(){

//     FILE *fodd;
//     int n;

//     fodd=fopen("OddNumbers.txt","w");

//     printf("Enter the range upto which you want to calculate the odd numbers:");
//     scanf("%d",&n);

//     for(int i=1; i<=n; i++){

//         if(i % 2 != 0)
//         fprintf(fodd,"%d\n",i);

//     }

//     fclose(fodd);

//     return 0;
// }

// #include<stdio.h>
// int main(){

//     FILE *sum;
//     int n,s=0;

//     sum=fopen("sum.txt","r");   //opening sum file in read mode

//     while (fscanf(sum,"%d",&n)!=EOF)    //reading the intergers one by one and storing it in n until the end of file
//     s+=n;
    
//     fclose(sum);    //closing the file

//     sum=fopen("sum.txt","w");   //again opening the file in write mode
//     fprintf(sum,"%d",s);    //printing the sum

//     fclose(sum);    //closing the file

//     return 0;

// }

// #include<stdio.h>

// #define MAX_SIZE 25
// int main(){

//     FILE *string;   
//     char str[MAX_SIZE];

//     string=fopen("sum.txt","w");

//     // fscanf(string,"%s",str);
//     // fgets(str,MAX_SIZE,string);
//     printf("Enter something:");
//     fgets(str,MAX_SIZE,stdin);

//     fprintf(string,"%s",str);


//     fclose(string);

//     return 0;
// }

#include<stdio.h>
#include<string.h>
#include<ctype.h>

enum macro{MAX_SIZE=15};

int main(){

    FILE *read;
    char str[MAX_SIZE];
    read=fopen("sum.txt","r");

    fgets(str,MAX_SIZE,read);

    fclose(read);

    int length=strlen(str);
    int countVowel=0;

    for(int i=0; i<length; i++){

        if(tolower(str[i])=='a' || tolower(str[i])=='e' || tolower(str[i])=='i' || tolower(str[i])=='o' || tolower(str[i])=='u')
        countVowel++;

    }

    read=fopen("sum.txt","w");

    fprintf(read,"%d",countVowel);

    fclose(read);

    return 0;

}