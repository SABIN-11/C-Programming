
#include <stdio.h>
#include <stdlib.h>

//function to check if an array is a consecutive array or not i.e if all the elements are in +1 order

// void check_consecutive(int *array, int size){

//     int smallest = array[0], largest = array[0];
//     int total_sum_of_elements = array[0];
//     for(int i = 1; i < size; i++){

//         total_sum_of_elements += array[i];

//         if(array[i] < smallest){
//             smallest = array[i];
//         }
//         if(array[i] > largest){
//             largest = array[i];
//         }

//     }

//     //finding the sum of the consecutive elements in the range [smallest, largest]
//     int sum_of_consecutive = ((largest - smallest + 1) * (smallest + largest)) / 2;

//     //checking if the array is consecutive or not
//     if(total_sum_of_elements == sum_of_consecutive)
//     printf("The array is consecutive.\n");
    
//     else
//     printf("The array is not consecutive.\n");



// }

void arrange_alternatively(int *array, int size){

    int *positive_array = (int *)malloc(size * sizeof(int));
    int *negative_array = (int *)malloc(size * sizeof(int));

    if (positive_array == NULL || negative_array == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int j = 0, k = 0;
    int length_positive = 0, length_negative = 0;

    for(int i = 0; i < size; i++){
        if(array[i] > 0){
            positive_array[j++] = array[i];
        }
        else{
            negative_array[k++] = array[i];
        }
    }

    length_negative = k - 1;
    length_positive = j - 1;
    j = k = 0;

    if(length_negative > length_positive){
        for(int i = 0; i < size; i++){
            
            if(i % 2 == 0)  printf("%d ",negative_array[k++]);
            else    printf("%d ",positive_array[j++]);

        }
    }
    else{
        for(int i = 0; i < size; i++){

            if(i % 2 == 0)  printf("%d ",positive_array[j++]);
            else    printf("%d ",negative_array[k++]);
        }
    }

    free(positive_array);
    free(negative_array);

}

    

int main(){
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

    // check_consecutive(array, number);
    arrange_alternatively(array, number);

    // Free the allocated memory
   free(array);

   return 0;
}