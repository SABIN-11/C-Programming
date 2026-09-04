
#include <stdio.h>
#include <stdlib.h>

//function to move all zeros towards the end
void move_zeros(int *array, int size){

    int k = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] != 0)
            array[k++] = array[i];
    }
    for(int i = k; i < size; i++)   array[i] = 0;

    for(int i = 0; i < size; i++)    printf("%d ",array[i]);

}

//function to convert an array in such a way that it doubles its value. If i and i + 1 elements are same
//i+1 will be 0 and i will be double

void double_value(int *array, int size){

    for(int i = 0; i < size - 1; i++){

        if(array[i] == array[i + 1]){
            array[i] = array[i] * 2;
            array[i + 1] = 0;
            i++;
        }
    }

    move_zeros(array, size);
    
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

    double_value(array, number);

    // Free the allocated memory
   free(array);

   return 0;
}