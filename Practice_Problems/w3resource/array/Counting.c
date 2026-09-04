
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

int maximum(int *array, int size){

     int max = INT_MIN;
     for(int i = 0; i < size; i++){
          if(array[i] > max){
               max = array[i];
          }
     }
     return max;
}
void print_Using_CountingSort(int *array, int size, int max){

     int *frequency = (int*)calloc((max + 1), sizeof(int));
     for(int i = 0; i < size; i++){
          frequency[array[i]]++;
     }
     int i = 0;
     while(i < max + 1){
          for(int j = 0; j < frequency[i]; j++){
               printf("%d ",i);
          }
          i++;
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

     int max = maximum(array, number);
     print_Using_CountingSort(array, number, max);

    // Free the allocated memory
   free(array);

   return 0;
}