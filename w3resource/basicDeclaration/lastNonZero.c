//finding the last non zero digit of a factorial of n

#include<stdio.h>

#define max 40

int factorial(int number){

    if(number <= 1)
    return 1;

    else{

        return number * factorial(number-1);
        
    }

}

int nonzero(int digit[max],int range){

    for(int i = 0; i < range; i++){

        if(digit[i] != 0)
        return digit[i];

    }
}

int main(){

    int number;

    printf("Enter a positive integer:");
    scanf("%d",&number);

    int fact=factorial(number);
    int digit[max]={0};
    int i=0;

    while(fact != 0){

        int remainder= fact % 10;
        digit[i++]=remainder;
        fact/=10;

    }

    printf("Last non-zero digit is %d.",nonzero(digit,i));

    return 0;
}