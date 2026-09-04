//left shifting by 2 bits

#include<stdio.h>

int main(){

    int number;

    printf("Enter the number:");
    scanf("%d",&number);

    printf("The left shifted data is %d",number << 2);

    return 0;
}