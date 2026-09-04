/*find the ceiling in the array of the value x*/
/*ceiling:element >= x but smallest comparing to other greater elements*/
#include <stdio.h>
#include <stdlib.h>

 /*as array is in ascending order just find the first element which is greater/equal to ceiling*/
int findCeiling(int *array, int ceiling, int number){

    for(int i = 0; i < number; i++){
        if(array[i] >= ceiling)
        return i;
    }
}

/*function to find the ceiling and floor of numbers from 0 to 10(inclusive) in a sorted array*/
/*1 3 5 7 8 9*/
void ceilingAndFloor(int *array, int number){

    for(int i = 0; i <= 10; i++){
        for(int j = 0; j < number; j++){
            if(array[j] >= i){
                printf("Ceiling of %d is %d.\n",i,array[j]);
                break;
            }
        }
    }

    printf("\n");

    for(int i = 0; i <= 10; i++){
        for(int j = 0; j < number; j++){
            if(array[j] > i && i == 0){
                printf("Floor of %d is %d.\n",i,-1);
                break;
            }
            if(array[j] > i){
                printf("Floor of %d is %d.\n",i,array[j - 1]);
                break;
            }
            else if(array[j] == i){
                printf("Floor of %d is %d.\n",i,array[j]);
                break;
            }
        }
            
    } 

}

int main() {
   int number,ceiling;

   printf("Enter the number of elements you want in the array: ");
   scanf("%d", &number);

   int *array = (int*)malloc(number * sizeof(int));

   if (array == NULL) {
        printf("Error while allocating the memory");
        exit(1);
   }

   for (int i = 0; i < number; i++)
        scanf("%d", array + i);

    //asking the user for the element whose ceiling is to be found
    printf("Enter the element whose ceiling is to be found:");
    scanf("%d",&ceiling);

    // int index=findCeiling(array, ceiling, number);
    // printf("Ceiling of %d is %d.",ceiling,array[index]);

    ceilingAndFloor(array, number);

    // Free the allocated memory
   free(array);

   return 0;
}