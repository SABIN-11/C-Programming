
#include <stdio.h>
#include <stdlib.h>

//function to find the pairs of elements that form a specific difference

// void print_Pairs(int *array, int size, int difference){

//     for(int i = 0; i < size; i++){
//         for(int j = 0; j < size; j++){
//             if(array[i] - array[j] == difference){ 
//                 printf("[%d,%d] ",array[i],array[j]);
//                 break;
//             }
//         }
//     }
// }

//function to print the most repititive element
void print_MostRepititive(int *array, int size){

    int frequency[size + 1];

    for(int i = 0; i < size; i++)   frequency[i] = 0;

    int max_freq = 0, max_freq_element = 0;
    //get the frequency of each element & also get the index of the maximum frequncy 
    for(int i = 0; i < size; i++){
        frequency[array[i]]++;
        if(frequency[array[i]] > max_freq){
            max_freq = frequency[array[i]];
            max_freq_element = array[i];
        }
    }

    // Check if there are multiple elements with the same max frequency
    int multiple_max_freq = 0;
    for (int i = 0; i < size; i++) {
        if(frequency[i] != max_freq) {
            multiple_max_freq = 1;
            break;
        }
    }

    // Print the result
    if(multiple_max_freq == 0){
        printf("There are multiple elements with the same max frequency.\n");
    }
    else if(multiple_max_freq == 1){
        printf("The most repititive element is %d.\n", max_freq_element);
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
    int frequency[number];
    for (int i = 0; i < number; i++){
        scanf("%d", array + i);
    }

    // print_Pairs(array, number, 5);
    print_MostRepititive(array, number);

    // Free the allocated memory
   free(array);

   return 0;
}