//converting octal into hexadecimal

// #include<stdio.h>
// #include<stdlib.h>

// //defining macro
// #define MAX_SIZE 10

// //structure defining
// struct conversion{

//     char octal[MAX_SIZE];
//     long int decimal;

// };

// int main(){

//     struct conversion convert={"677",0,"0",0};  //initializing

//     convert.decimal=strtol(convert.octal,NULL,8);

//     printf("%X",convert.decimal);

//     return 0;

// }

#include<stdio.h>
#include<stdlib.h>

int main(){

    char octal[10]="457xyz";
    char *endptr;

    long int decimal=strtol(octal,&endptr,8);

    if(endptr==octal)
    printf("No conversion was done.");

    else if(endptr!='\0')
    printf("Remaining characters that were not converted are %s",endptr);

    else
    printf("Conversion was successful");

    printf("\nDecimal value is %ld.",decimal);


    return 0;


}