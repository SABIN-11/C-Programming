//input a 7 digit number and print its digit 

#include<stdio.h>

int main(){

    int number;

    printf("Enter a 7 digit number:");
    scanf("%d",&number);

    int reverse[7];
    int i=0;

    while(number > 0){

        int remainder=number % 10;

        reverse[i++]=remainder;

        number/=10;
    }

    for(int k = 6; k >= 0; k--) printf("%d\t",reverse[k]);
    

    return 0;
}