
#include <stdio.h>
#include <stdlib.h>

//function to return the no of clump found in the array. clump means a series of same adjacent elements

// int clumps_count(int *array, int size){

//     int ctr_clumps = 0, j;

//     for(int i = 0; i < size; i++){

//         if(i == size - 1)   break;

//         if(array[i] == array[i + 1]){
//             ctr_clumps++;

//             for(j = i; array[j + 1] == array[i] && j < size - 1; j++);
//             i = j;

//         }

//     }
//     return ctr_clumps;

// }

//function to modify array as arr[i] = i if i is not present in the array, if present arr[i] = -1

void modify_Array(int *array, int size){

    int found;  //to check if i is present in the array

    int *array_2 = (int *)malloc(size * sizeof(int));
    if(array_2 == NULL){
        printf("Memory not allocated");
        exit(1);
    }
    int k = 0;

    for(int i = 0; i < size; i++){

        found = 0;

        for(int j = 0; j < size; j++){

            if(array[j] == i){
                found = 1;
                array_2[k++] = i;
                break;
            }

        }
        if(!found)  array_2[k++] = -1;
    }

    for(int i = 0; i < k; i++)  printf("%d ",array_2[i]);

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

   for (int i = 0; i < number; i++)
        scanf("%d", array + i);

    // printf("The number of clumps in the array is %d.",clumps_count(array, number));
    modify_Array(array, number);

    // Free the allocated memory
   free(array);

   return 0;
}