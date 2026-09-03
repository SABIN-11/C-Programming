/*finding the number of combinations of a, b, c and d (0 ≤ a, b, c, d ≤ 9) where (a + b + c + d) will be equal to n.
Input:
n (1 <= n <= 50)*/

#include<stdio.h>

int main(){

    int number;

    printf("Enter a number([1,50]):");
    scanf("%d",&number);    

    if(number < 1 || number > 50){
        printf("ERROR! The value of number is out of the range i.e 1-50");
        return 1;
    }

    int count=0;

    for(int i = 0; i <= 9; i++){

        for(int j = 0; j <= 9; j++){

            for(int k = 0; k <= 9; k++){

                for(int l = 0; l <= 9; l++){

                    if(i + j + k + l == number){

                        printf("%d + %d + %d + %d = %d",i,j,k,l,number);
                        count++;
                        printf("\n");
                        
                    }

                }

            }

        }

    }

    printf("There are total %d permutations.",count);

    return 0;
}