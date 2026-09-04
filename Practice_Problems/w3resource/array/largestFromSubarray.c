
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//function to find the largest element frome each contagious subarray of k elements

// void largest_from_subarray(int *array, int size, int k){

//     int temp = k;
//     int i = 0, max;

//     printf("The contigious subarray of length %d and their maximum value are:\n", k);

//     while(i < size){

//         max = INT_MIN;  //assigning minimum value to max for each start of a new subarray
//         k = temp;

//         if(i + k - 1 >= size)   return;

//         while(k >= 1){

//             printf("%d ",array[i]);
//             if(array[i] > max)  max = array[i];

//             i++;
//             k--;

//         }
//         printf("------> %d\n",max);
//         i = i - temp + 1;
//     }
    

// }

//function to segragate the 0's and 1's

// void segragate_array(int *array, int size){

//     int *array_2 = (int *)calloc(size, sizeof(int));
//     if(array_2 == NULL){
//         printf("Memory allocation failed\n");
//         exit(1);
//     }
//     int k = 0;
//     for(int i = 0; i < size; i++){
//         if(array[i]){
//             array_2[k++] = 1;
//         }
//     }

//     for(int i = 0; i < size; i++)   printf("%d ",array_2[i]);


//     free(array_2);
// }

//function to find the first peak element

int peak_element(int *array, int size){

    if(size == 1 || array[0] >= array[1])    return 0;
    if(array[size - 1] >= array[size - 2])   return size - 1;

    for(int i = 1; i < size - 1; i++)
    if(array[i] >= array[i - 1] && array[i] >= array[i + 1])    return i;

    return -1;
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

    int index = peak_element(array, number);

    if(index != -1)
    printf("The first peak element is array[%d]:%d.",index, array[index]);
    
    else
    printf("No peak element found.");

    // segragate_array(array, number);

    // largest_from_subarray(array, number, 3);
    

    // Free the allocated memory
   free(array);

   return 0;
}