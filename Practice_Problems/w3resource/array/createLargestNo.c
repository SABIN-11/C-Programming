
#include <stdio.h>
#include <stdlib.h>


void create_Largest_No(int *array, int size){

    // Calculate the maximum number of digits required
    int digit_count = 0;
    for (int i = 0; i < size; i++) {
        int temp = array[i];
        while (temp > 0) {
            digit_count++;
            temp /= 10;
        }
    }

    // Allocate memory based on digit count
    int *array_2 = (int *)malloc(digit_count * sizeof(int));

    if (array_2 == NULL) {
        perror("Error while allocating the memory.");
        exit(1);
    }

    int k = 0;

    // Extract digits
    for (int i = 0; i < size; i++) {
        int temp = array[i];
        while (temp > 0) {
            array_2[k++] = temp % 10;
            temp = temp / 10;
        }
    }

    // Sort digits in descending order
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (array_2[i] < array_2[j]) {
                int temp = array_2[i];
                array_2[i] = array_2[j];
                array_2[j] = temp;
            }
        }
    }

    // Print the result
    printf("Number thus created is ");
    for (int i = 0; i < k; i++) {
        printf("%d", array_2[i]);
    }
    printf("\n");

    // Free the allocated memory
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

    create_Largest_No(array, number);

    // Free the allocated memory
   free(array);

   return 0;
}