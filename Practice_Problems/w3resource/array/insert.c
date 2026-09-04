#include <stdio.h>
#include <stdlib.h>

int *insertElement(int *array, int number, int element, int position){
   //reallocating the memory by adding 4 bytes for the extra element to be inserted
   int *array_2=(int *)realloc(array, (number + 1)*sizeof(int));

   for(int i = number; i > position; i--){ 
      array_2[i]=array_2[i-1];
   }

   array_2[position]=element;
   return array_2;   //returning the base address of the array_2
}

int main() {
   int number;

   printf("Enter the number of elements you want in the array: ");
   scanf("%d", &number);

   //allocating some memory for the array
   int *array = (int*)malloc(number * sizeof(int));

   if (array == NULL) {
        printf("Error while allocating the memory");
        exit(1);
   }

   for (int i = 0; i < number; i++)
        scanf("%d", array + i);

   int element,position;
   //asking the user for the element to be inserted in a certain position
   printf("Enter the element you want to insert:");
   scanf("%d",&element);
   printf("\nEnter the position where you want it to be inserted:");
   scanf("%d",&position);


   int *array_2=insertElement(array, number, element, position - 1);

   printf("Array after inserting a element");
   for(int i = 0; i < number + 1; i++)
   printf("%d\t",*(array_2 + i));
    // Free the allocated memory
   free(array);
   free(array_2);

   return 0;
}