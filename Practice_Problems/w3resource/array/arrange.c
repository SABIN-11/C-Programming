
#include <stdio.h>
#include <stdlib.h>

//function to sort elments in such a way that smallest,largest,second smallest,second largest and so on

// void sort(int *array, int size){

//     //arranging in ascending order first
//     int temp = 0;

//     for(int i = 0; i < size; i++){
//         for(int j = i+1; j < size; j++){
//             if(array[j] < array[i]){
//                 temp = array[i];
//                 array[i] = array[j];
//                 array[j] = temp;
//             }
//         }
//     }

//     //now sorting according to the question
//     int start = 0, end = size - 1;
//     while(start <= end){
//         if(start == end){
//             printf("%d",array[start]);
//             break;
//         }


//         printf("%d ",array[start++]);
//         printf("%d ",array[end--]);

//     }
// }   

//function to sort elements such that the elements at even index must be smaller than next element 
//elements at odd index must me greater than next element

void rearrange_Odd_Even(int *array, int size){

    int temp = 0;

    for(int i = 0; i < size - 1; i++){

        if(i % 2 == 0) {   // If index is even
            if(array[i] > array[i + 1]) {  // Check if the current element is greater than the next element
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
        else {   // If index is odd
            if(array[i] < array[i + 1]) {  // Check if the current element is smaller than the next element
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }

    for(int i = 0; i < size; i++)   printf("%d ",array[i]);
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

    // sort(array, number);
    rearrange_Odd_Even(array, number);

    // Free the allocated memory
   free(array);

   return 0;
}