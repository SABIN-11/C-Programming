//printing hollow square by taking side as an input

#include<stdio.h>

int main(){

    int size;

    printf("Enter the size of the side:");
    scanf("%d",&size);

    for(int i = 1; i <= size; i++){

        for(int j = 1; j <= size; j++){

            if(i == 1 || j == 1 || i == size || j == size)  printf("#");

            else
            printf(" ");

        }
        printf("\n");
    }

    return 0;
}