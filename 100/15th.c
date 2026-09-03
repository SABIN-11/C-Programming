//number system conversion using strtol function

// #include<stdio.h>
// #include<stdlib.h>

// #define MAX 15

// int main(){

//     char octal[MAX]="70000";
//     long int decimal=strtol(octal,NULL,8);

//     printf("Decimal value of %s is %ld.",octal,decimal);

//     return 0;
// }

// #pragma pack(1) //special purpose directive used to turn on or off certain features
// // #pragma warn +xxx //to show warnings
// // #pragma warn -xxx //to remove warnings
// struct{
//     int a[100];
//     int b;
//     char c;
// }var;

// #include<stdio.h>
// int main(){

//     printf("%d",sizeof(var));
//     return 0;
// }

// #include<stdio.h>
// struct student{

//     int age;
// };
// int main(){

//     struct student data={16};
//     struct student *ptr=&data;

//     printf("%d",(*ptr).age);
//     return 0;
    
// }

// #include<stdio.h>
// #include<stdlib.h>

// int main(){

//     char hexadecimal[5]="AE04";
//     int decimal=strtol(hexadecimal,NULL,16);

//     printf("%d",decimal);

//     return 0;
// }


// #include<stdio.h>
 
// union store{
//     int a;
//     char b;
//     double c;   
// }var;

// int main(){

//     var.b='Z';
//     var.c=65.382;
//     var.a=65;

//     printf("Size:%d",sizeof(var));

//     printf("\n%d",var.a);
//     printf("\n%c",var.b);
//     printf("\n%d",var.c);
    
//     return 0;
// }

// #include<stdio.h>

// enum variable{a=1,b,c,d,e,f};

// int main(){

//     // enum variable var;
//     // var=a;
//     printf("%5d%5d%5d%5d%5d",a,b,c,d,e);

//     return 0;

// }

