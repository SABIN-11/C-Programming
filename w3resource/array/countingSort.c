/*sorting an array in 0's, 1's and 2's*/

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

// void countingSort(int *array, int size){

//     int count_zero, count_one, count_two;
//     count_zero = count_one = count_two = 0;

//     for(int i = 0; i < size; i++){
//         if(array[i] == 0)   count_zero++;
//         else if(array[i] == 1)   count_one++;
//         else if(array[i] == 2)   count_two++;
//     }

//     for(int j = 0; j < count_zero; j++) array[j] = 0;
//     for(int j = count_zero; j < count_zero + count_one; j++) array[j] = 1;
//     for(int j = count_zero + count_one; j < size; j++) array[j] = 2;

//     for(int i = 0; i < size; i++)   printf("%d ",array[i]);
// }

// bool subset(int *array, int size_1){
    
//     int subArray[5] = {5, 4, 2, 0, 6};
//     //to count the same element 
//     int countSub = 0;
//     for(int i = 0; i < 5; i++){
//         for(int j = 0; j < size_1; j++){
//             if(subArray[i] == array[j]){
//                 countSub++;
//                 break;  
//             }
            
//         }
//     }

//     return (countSub == 5)?true:false;
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

    // countingSort(array, number);
    if(subset(array, number))   printf("Second array is subset of first.");

    // Free the allocated memory
   free(array);

   return 0;
}