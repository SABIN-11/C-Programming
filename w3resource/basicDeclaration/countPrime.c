/*counting the prime numbers below n 1<=n<=999999*/

#include<stdio.h>

int countPrime(int range){

    //using sieve of eratosthenes method

    int prime[range];
    int count=0;

    for(int i = 0; i < range; i++)
    prime[i]=1;

    for(int k = 2; k*k < range; k++){

        if(prime[k] == 1){

            for(int j = k*k; j < range; j+=k){

                prime[j]=0;

            }

        }
    }

    for(int i = 2; i < range; i++){

        if(prime[i] == 1)
        count++;
        
    }

    return count;

}

int main(){

    int range;
    printf("Enter the range:");
    scanf("%d",&range);

    if(range < 1 || range > 999999){

        printf("ERROR! Number exceeds the range.");
        return 1;

    }
    printf("There are %d prime below %d.",countPrime(range),range);


    return 0;
}