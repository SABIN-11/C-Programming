/*replace the current element with the largest element on its right side*/
#include <stdio.h>
#include <stdlib.h>

// int largestOnRight(int *array, int index, int size){
    
//     int MAX = -1; //to store the maximum element
//     if(index == size)   return 0;

//     else{
//         while(index < size){
//             if(array[index] > MAX)  MAX = array[index];
//             index++;
//         }
//     }
//     return MAX;
// }

// void replace(int *array, int size){

//     for(int i = 0; i < size; i++){
//         array[i] = largestOnRight(array, i + 1, size);
//         printf("%d ",array[i]);
//     }
// }

int median(int *array, int size){

    int n = size - 1;   //for the formula of median
    if(n % 2 == 0)  return array[n/2];
    else return (array[n / 2] + array[n / 2 + 1]) / 2;
    
}

void merge(int *array, int *array_2, int size){

     int k = 0, temp;
     //merging first array in second array
     for(int i = size; i < 2 * size; i++){
          array_2[i]=array[k++];
     }

     //sorting the merged array in ascending order
     for(int i = 0; i < 2 * size; i++){
          for(int j = i + 1; j < 2 * size; j++){
               if(array_2[i] > array_2[j]){
                    temp=array_2[i];
                    array_2[i]=array_2[j];
                    array_2[j]=temp;
               }
          }
     }

    printf("Median is %d.",median(array_2, 2 * size));
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

    int *array2 = (int*)malloc(number * sizeof(int));

   if (array2 == NULL) {
        printf("Error while allocating the memory");
        exit(1);
   }

   for (int i = 0; i < number; i++)
        scanf("%d", array2 + i);

    // replace(array, number);
    merge(array, array2, number);

    // Free the allocated memory
   free(array);

   return 0;
}