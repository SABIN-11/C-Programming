/*rearrange the array: if the 2 consecutive elements are same change the first element by doubling its value and 
another one by 0 and move all zero's to the end*/

#include <stdio.h>
#include <stdlib.h>

void rearrangeArray(int number, int *array, int i){

    // for(int i = 0; i < number; i++){
    //     if(array[i] == array[i + 1]){
    //         array[i] = array[i] * 2;
    //         array[i + 1] = 0;
    //         i++;
    //     }
    // }
    if(i >= number) return;

    if(array[i] == array[i + 1]){
            array[i] = array[i] * 2;
            array[i + 1] = 0;
            i++;
    }
    rearrangeArray(number, array, i + 1);
}

void moveZeros(int number, int *array){

    int *array_2=(int *)calloc(number, sizeof(int));
    int k = 0;

    for(int i = 0; i < number; i++){
        if(array[i] != 0){
            array_2[k++]=array[i];
        }
    }

    printf("Array after rearranging:\n");

    for(int i = 0; i < number; i++)
    printf("%d ",array_2[i]);

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

    rearrangeArray(number, array, 0);
    moveZeros(number, array);
    // Free the allocated memory
   free(array);

   return 0;
}