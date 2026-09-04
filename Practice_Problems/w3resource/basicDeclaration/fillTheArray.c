//fill the array from 0 to n-1  2 ≤ n ≤ 10

#include<stdio.h>

int main(){

    int range; //for range-1

    printf("Enter the range(2-10):");
    scanf("%d",&range);

    if(range < 2 || range > 10){

        printf("ERROR! Number exceeds the range limit i.e (2 <= range <= 10)");
        return 1;

    }
    int array[range];

    for(int k = 0; k <= range - 1; k++){

        array[k]=k;
        printf("array[%d]:%d\n",k,array[k]);

    }
    
    return 0;
}