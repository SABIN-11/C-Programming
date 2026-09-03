//find the prime palindrome numbers between x and y.(5<=x<y<1000000000)

#include<stdio.h>

#define max 1000000000

int main(){

    int lower,upper;

    printf("Enter the lower range and upper range:");
    scanf("%d%d",&lower,&upper);

    if(lower < 5 || upper < lower || upper > max){

        printf("Error! Your range doesn't matches the size criteria.");
        return 1;

    }

    int size=upper - lower + 1;
    int k=0;

    int prime[size];

    for(int i = lower; i <= upper; i++){

        int count=0;

        for(int j = 2; j <= i; j++){

            if(i % j == 0)  count++;

        }

        if(count == 1){

            prime[k]=i;
            k++;

        }

        
    }

    for(int i = 0; i < k; i++){

        int reverse=0;
        int temp=prime[i];

        while(prime[i] != 0){

            int remainder=prime[i] % 10;
            reverse= reverse * 10 + remainder;
            prime[i]/=10;

        }

        if(temp == reverse)
        printf("%d\t",temp);

    }


    return 0;
}