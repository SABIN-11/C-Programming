/*find the smallest missing element in an array
eg:[0,1,3,4,5,6,8,9]
missing elements:2,7 
smallest missing element:2
*/

#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<math.h>

int smallestMissingNumber(int *array, int number){

    int smallest=INT_MAX;
    for(int i = 0; i < number; i++){
        if(array[i] + 1 != array[i + 1]){
            if(array[i] + 1 < smallest){
                smallest = array[i] + 1;
            }
        }
    }

    return smallest;

}

void nextBiggerElement(int *array, int number){

    for(int i = 0; i < number; i++){
        if(i == number - 1){
            printf("\nNext bigger element of %d in the array is %d.",array[i],-1);
            break;
        }
        for(int j = i + 1; j < number; j++){
            if(array[i] < array[j]){
                printf("\nNext bigger element of %d in the array is %d.",array[i],array[j]);
                break;
            }
        }
    }

}

void closestToZero(int *array, int number){

    int firstElementIndex,secondElementIndex;
    int count=INT_MAX;

    //comparing every element with each other to find the lowest absolute sum
    for(int i = 0; i < number; i++){
        for(int j = i + 1; j < number; j++){
            if(abs(array[i] + array[j]) < count){
                count = abs(array[i] + array[j]);
                //for the pair of elements
                firstElementIndex = i;
                secondElementIndex = j;
            }
        }
    }

    printf("The pair of elements whose sum is closest to zero are [%d,%d].",array[firstElementIndex],array[secondElementIndex]);

}


int main() {
   int number;

   printf("Enter the number of elements you want in the array: ");
   scanf("%d", &number);

   int *array = (int*)malloc(number * sizeof(int));

   if (array == NULL) {
        printf("Error while allocating the memory");
        exit(1);
   }

    for(int i = 0; i < number; i++)
    scanf("%d", array + i);

    // printf("The smallest missing element is %d.",smallestMissingNumber(array, number));
    // nextBiggerElement(array, number);
    closestToZero(array, number);

    // Free the allocated memory
   free(array);

   return 0;
}