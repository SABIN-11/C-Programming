//find the numbers( 1 - 100) when divided by n gives remainder 3

#include<stdio.h>

int main(){

    int number;
    printf("Enter the integer:");
    scanf("%d",&number);

    for(int i = 1; i <= 100; i++)
    if(i % number == 3) printf("%d\n",i);
    

    return 0;
}