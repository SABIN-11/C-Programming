//header files in the system
#include<stdio.h> 
#include<conio.h>
//local file in my directory
#include "preprocessor.c"

#define PI 3.141f   //defining a macro

void main(){
    
    printf("Sum is %d",sum(10, 20));
    printf("\nPi is %f",PI);

    #ifdef PI   //if macro is defined
    printf("\nPI is defined");
    #endif

    #undef PI   //undefining a macro

    #ifndef PI  //if macro is undegfined
    printf("\nPI is not defined");
    #endif

    printf("\nCurrent file name:%s",__FILE__);
    printf("\nCurrent date :%s",__DATE__);
    printf("\nCurrent time :%s",__TIME__);
    printf("\nANSI:%d",__STDC__);
    getch();

}