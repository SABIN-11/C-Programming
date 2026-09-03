/*finding the maximum sum of the elements which are not adjacent i.e side by side*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int non_Adjacent_Sum(int *array, int size){

    int maximum_Sum = INT_MIN;
    int current_Sum;
    for(int i = 0; i < size; i++){
        current_Sum = 0;
        for(int j = i; j < size; j+=2){
            current_Sum += array[j];
            if(current_Sum > maximum_Sum)   maximum_Sum = current_Sum;
        }
    }
    return maximum_Sum;
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

    printf("Maximum sum is %d.",non_Adjacent_Sum(array, number));
    // Free the allocated memory
   free(array);

   return 0;
}