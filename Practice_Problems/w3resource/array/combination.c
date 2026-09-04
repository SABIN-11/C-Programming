
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//function to find all the combinations of the elements of an array
void combinations(int *array, int size){

    bool *make_it_false = (bool *)malloc((size + 1) * sizeof(bool));
    if(make_it_false == NULL){
        printf("Memory error\n");
        exit(1);
    }

    printf("\n\nThe combinations are \n");
    for(int i = 0; i < 5; i++){

        for(int k = 0; k < size; k++)   make_it_false[k] = true;
        make_it_false[i] = false;

        for(int j = 0; j < size; j++){
            if(make_it_false[j])    printf("%d ",array[j]);
        }
        printf("\n");

    }

    free(make_it_false);
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

    combinations(array, number);

    // Free the allocated memory
   free(array);

   return 0;
}