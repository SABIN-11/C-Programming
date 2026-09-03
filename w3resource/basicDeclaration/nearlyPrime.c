//the numbers which can we obtained by the product of two prime numbers is nearly prime numbers

#include<stdio.h>
#include<stdbool.h>

#define max 50

//using sieve of eratosthenes method to get prime numbers and storing all prime numbers in prime array
int getPrime(int prime[max], int nonPrime){

    bool is_true[max+1];    

    for(int i = 0; i < nonPrime; i++)
    is_true[i]=true;

    //sieve of eratosthenes method
    for(int i = 2; i*i <= nonPrime; i++){       //finding prime upto to the squareroot of number

        if(is_true[i]){

            for(int j = i * i; j <= nonPrime; j+=i){

                is_true[j]=false;   //assignning false to those numbers which are getting truncuated

            }

        }
    }
    int k=0;
    for(int i = 2; i <= nonPrime; i++){

        if(is_true[i]){
            prime[k++]=i;
        }
    }

    return k;   //returning to know the range of the prime array

}

//to check if the number is product of 2 prime numebers or not
bool nearlyPrime(int prime[max], int nonPrime, int range){

    for(int i = 0; i < range; i++){

        if(nonPrime % 2 == 0){ //if the number is even

            /*if it is even then the only prime even number is 2 and evem * odd is even so multiplying every other 
            element by only 2*/
            if(prime[0] * prime[i] == nonPrime)
            return true;
            
        }
        else{   //if odd
            
            //using nested loop for odd as odd * odd = odd
            for(int k = 0; k < range; k++){

                if(prime[i] * prime[k] == nonPrime)
                return true;

            }
        }
    }

    return false;

}

int main(){

    int nonPrime;
    int prime[max];
    printf("Enter a non-prime number:");
    scanf("%d",&nonPrime);

    if(nonPrime <= 3){
        printf("Error! Number must be larger than 3 to be multiplicable by 2 prime numbers.");
        return 1;
    }

    int range=getPrime(prime,nonPrime);

    if(nearlyPrime(prime,nonPrime,range))
    printf("%d is nearly prime number.",nonPrime);
    
    else
    printf("%d is not nearly prime number.",nonPrime);

    return 0;
}