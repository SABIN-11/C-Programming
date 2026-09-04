
#include <stdio.h>
#include <stdlib.h>

//function to find the length of the subarray such that sorting that subarray sorts the entire array

void minimum_subarray(int *array, int size){

    int high_position = 0, low_position = 0, new_index = 0;
    int i;

    for(i = 1; i < size - 1; i++){
            if(array[i] < array[i - 1]){
                high_position = i - 1;
                break;
            }
    }

    for(int j = i + 1; j < size - 1; j++){
        if(array[j] > array[high_position]){
            high_position = j - 1;
            break;
        }
    }

    for(i = 0; i <= high_position; i++){
        if(array[i] > array[high_position]){
            low_position = i;
            break;
        }
    }

    printf("The minimum unorted subarray that makes the array sorted when it is sorted lies between %d and %d",low_position, high_position);
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

   for (int i = 0; i < number; i++)
        scanf("%d", array + i);
    
    minimum_subarray(array, number);

    // Free the allocated memory
   free(array);

   return 0;
}