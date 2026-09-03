
#include <stdio.h>
#include <stdlib.h>

//function to rearrange the array such that arr[i] becomes arr[arr[i]]

void rearrange_array(int *array, int size){

    int *array_2 = (int *)malloc(size * sizeof(int));

    if(array_2 == NULL){
        printf("Memory not allocated");
        exit(1);
    }

    for(int i = 0; i < size; i++){
        array_2[i] = array[array[i]];
    }

    printf("After modifying:\n");
    for(int i = 0; i < size; i++)   printf("%d ",array_2[i]);

    free(array_2);
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

    for(int i = 0; i < number; i++){
        scanf("%d",array + i);
    }

    rearrange_array(array, number);

    // Free the allocated memory
   free(array);

   return 0;
}