//finding the highest value and its input position

#include<stdio.h>

int main(){

    int range;
    printf("Enter the range:");
    scanf("%d",&range);

    printf("Input %d integers:",range);

    int integers;
    int position=0;
    int greatest=-1;

    for(int i = 1; i <= range; i++){
        
        scanf("%d", &integers);

        if(integers > greatest){

        greatest=integers;
        position++;

        }

    }
    
    printf("Highest value:%d",greatest);
    printf("\nPosition:%d",position);
    return 0;
}