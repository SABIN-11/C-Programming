#include <stdio.h>
#include <stdlib.h>

void merge(int *array, int *array_2, int n1, int n2){

     int k = 0, temp;
     //merging first array in second array
     for(int i = n2; i < n2 + n1; i++){
          array_2[i]=array[k++];
     }

     //sorting the merged array in descending order
     for(int i = 0; i < n2 + n1; i++){
          for(int j = i + 1; j < n2 + n1; j++){
               if(array_2[i] < array_2[j]){
                    temp=array_2[i];
                    array_2[i]=array_2[j];
                    array_2[j]=temp;
               }
          }
     }

     //printing after sorting
     printf("After merging and sorting in descending order:\n");
     for(int i = 0; i < n2 + n1; i++)
     printf("%d\t",array_2[i]);

}

int main() {
   int number1, number2;

   printf("Enter the number of elements you want in the first array: ");
   scanf("%d", &number1);

    //input for array 1
   int *array = (int*)malloc(number1 * sizeof(int));

   if (array == NULL) {
        printf("Error while allocating the memory");
        exit(1);
   }

   for (int i = 0; i < number1; i++)
        scanf("%d", array + i);

    printf("Enter the number of elements you want in the second array: ");
    scanf("%d", &number2);
    //input for array 2
    int *array_2 = (int*)malloc(number2 * sizeof(int));

   if (array_2 == NULL) {
        printf("Error while allocating the memory");
        exit(1);
   }

   for (int i = 0; i < number2; i++)
        scanf("%d", array_2 + i);

    merge(array, array_2, number1, number2);

    // Free the allocated memory
   free(array);
   free(array_2);

   return 0;
}