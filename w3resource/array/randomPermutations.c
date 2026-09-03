/*printing the array elements in a random order in every execution*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void random_Permuatations(int *array, int size){

    srand(time(NULL));  //seedind different value everytime to get different random numbers everytime
    int random = 0; //random index
    int count = 0;  //to count how many unique index elements has been printed

    bool is_not_used[size];

    for(int i = 0; i < size; i++)   is_not_used[i] = true;

    while (count < size){

        random = rand() % size;

        if(is_not_used[random]){
            printf("%d ", array[random]);
            count++;
            is_not_used[random] = false;
        }

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

    random_Permuatations(array, number);

    // Free the allocated memory
   free(array);

   return 0;
}