//take a integer as an input and print histogram bars according to the integer value

#include<stdio.h>

#define hash '#'

void printingHistogram(int limit){      

    printf("Enter the integer values:");

    int bars[limit];

    for(int i = 0; i < limit; i++)
    scanf("%d",&bars[i]);

    for(int j = 0; j < limit; j++){

        for(int k = 1; k <= bars[j]; k++)
        printf("%c",hash);

        printf("\n");
    }

}

int main(){

    int limit;

    printf("Enter the number of histogram bars(Maximum:10):");
    scanf("%d",&limit);

    if(limit > 10){

        printf("ERROR! %d exceeds the maximum value limit i.e 10.",limit);
        return 1;

    }

    printingHistogram(limit);


    return 0;
}