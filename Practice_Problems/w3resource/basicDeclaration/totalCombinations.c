/*read n digits from 0-9 and prints the number of combinations equal to sum*/

#include<stdio.h>

int combinations(int numberOfDigits, int sum){

    int count=0;
    for(int i = 0; i < 9; i++){

        for(int j = i + 1; j < 9; j++){

            for(int k = j + 1; k < 9; k++){

                    if(i + j + k == sum)  count++;

            }
        }
    }

    return count;
}

int main(){

    int numberOfDigits, sum;
    printf("Enter the number of digits:");
    scanf("%d",&numberOfDigits);

    printf("Enter the sum:");
    scanf("%d",&sum);

    printf("Total combinations are %d.",combinations(numberOfDigits,sum));

    return 0;
}