
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//function to find the largest span of the same values

// int largest_span(int *array, int size){

//     int count;
//     int max_span = 0;

//     for(int i = 0; i < size - 1; i++){
//         for(int j = i + 1; j < size; j++){
//             if(array[i] == array[j]){
//                 if(j - i + 1 > max_span)  max_span = j - i + 1; 
//             }
//         }
//     }

//     return max_span;
// }

//function to return true if an array can be split in such a way that the right side sum and left side sum are equal

// bool can_be_split(int *array, int size){

//     int left_sum, right_sum;

//     for(int i = 0; i < size; i++){
//         left_sum = right_sum = 0;

//         for(int j = 0; j < size; j++){
//             if(j < i) left_sum += array[j];
//             else right_sum += array[j];
//         }
//         if(right_sum == left_sum)    return true;
        
//     }
//     return false;
// }



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

    // printf("The largest span between the same values is %d",largest_span(array, number));
    if(can_be_split(array, number))    printf("The array can be split in a position where the sum of both side are equal.");
    else    printf("The array can not be split in a position where the sum of both side are equal.");

    // Free the allocated memory
   free(array);

   return 0;
}