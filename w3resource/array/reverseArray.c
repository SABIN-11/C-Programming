#include <stdio.h>
#include <stdlib.h>

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

    for (int i = number - 1; i >= 0; i--)
    printf("%d\t",*(array + i));

    // Free the allocated memory
   free(array);

   return 0;
}