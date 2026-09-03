/*finding the equilibrium index : the index in which the sum of elements of on the right and left is same*/

#include <stdio.h>
#include <stdlib.h>

//function to calculate the equilibrium index

// void equilibrium_index(int *array, int size){

//     int right_sum = 0, left_sum = 0;
//     int total_sum = 0;

//     for(int i = 0; i < size; i++)   total_sum += array[i];

//     printf("The equilibrium indices:\n");
//     for(int i = 0; i < size; i++){

//         right_sum = total_sum - left_sum - array[i];

//         if(right_sum == left_sum)   printf("%d ",i);

//         left_sum += array[i];
//     }
// }

//function to find the maximum element in an array that is first increasing then decreasing

int max_element(int *array, int size, int start, int end){

     while(start <= end){
          int mid = (start + end) / 2;

          if(mid > 0 && mid < size - 1){
               if(array[mid] > array[mid - 1] && array[mid] > array[mid + 1])   return array[mid];
               else if(array[mid] > array[0])     start = mid + 1;
               else     end = mid - 1;
          }
          else if(mid == 0){
               if(array[mid] > array[mid + 1])   return array[mid];
               else    return array[mid + 1];
          }
          else if(mid == size - 1){
               if(array[mid] > array[mid - 1])    return array[mid];
               else    return array[mid - 1];
          }

     }

     
     
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

     //equilibrium_index(array, number);
     printf("The maximum element which is increasing then deacreasing is %d",max_element(array, number, 0, number - 1));

    // Free the allocated memory
   free(array);

   return 0;
}