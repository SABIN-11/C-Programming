/*deleting a element from a certain postion in the array*/
#include <stdio.h>
#include <stdlib.h>

void delete(int *array, int n, int position){

    int temp;
    for(int i = position; i < n; i++){
        temp=array[i];
        array[i]=array[i+1];
        array[i+1]=temp;
    }

    int *array_2=(int *)realloc(array, (n - 1) * sizeof(int));

    if (array == NULL) {
        printf("Error while allocating the memory");
        exit(1);
    }

    //printing the array after deleting a element from the array
    printf("After deleting:\n");
    for(int i = 0; i < n - 1; i++)
    printf("%d\t",*(array_2 + i));

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

    int position;
   //asking the user for the postion of the element to be deleted
   printf("\nEnter the position of the element to be deleted from the array:");
   scanf("%d",&position);

   delete(array, number, position - 1);

 // Free the allocated memory
   free(array);

   return 0;
}