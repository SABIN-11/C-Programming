/*find the inversions of elements in the given array:inversion pairs condition:first element must > second and apper before second*/
#include <stdio.h>
#include <stdlib.h>

// int count_Inversions(int *array, int size){

//     int count = 0;
//     for(int i = 0; i < size; i++){
//         for(int j = i + 1; j < size; j++){
//             if(array[i] > array[j]){
//                 printf("(%d, %d)\t",array[i],array[j]);
//                 count++;
//             }
//         }
//     }

//     return count;
// }

// int maximum_Difference(int *array, int size){

//     int max = array[0], max_index = 0;
//     int min = array[0];

//     //finding the largest element 
//     for(int i = 1; i < size; i++){
//         if(array[i] > max){
//             max = array[i];
//             max_index = i;
//         }
//     }

//     //finding the smallest element before the largest element
//     for(int i = 1; i < max_index; i++){
//         if(array[i] < min)  min = array[i];
//     }

//     return max - min;

// }

// void printUnique(int *array, int size){

//     int flag;
//     printf("Unique elements:");
//     for(int i = 0; i < size; i++){
//         flag = 0;
//         for(int j = 0; j < size; j++){
//             if(i != j){
//                 if(array[i] == array[j]){
//                     flag = 1;
//                     break;
//                 }
//             }
//         }
//         if(flag == 0)   printf("%d\t",array[i]);
//     }
// }

// void combination_Of_Four(int *array, int size, int target){

//     for(int i = 0; i < size; i++){
//         for(int j = i + 1; j < size; j++){
//             for(int k = j + 1; k < size; k++){
//                 for(int l = k + 1; l < size; l++){
//                     if(array[i] + array[j] + array[k] + array[l] == target){
//                         printf("%d + %d + %d + %d = %d", array[i], array[j], array[k], array[l], target);
//                         return;
//                     }
//                 }
//             }
//         }
//     }
    
// }

//function to sort an array in ascending order in the range [0,n^2]
void sort_In_Range(int *array, int size){

    int temp = 0, i = 0;
    int changing_index = size - 1;  //index where the number greater than n ^ 2 is going to be replaced

    while(i <= changing_index){
        if(array[i] > size * size){
            temp = array[i];
            array[i] = array[changing_index];
            array[changing_index] = temp;
            changing_index--;   //to make new place for the next changing element
            i--;    //to check if the replaced element > n ^ 2 
        }
        i++;
    }  
    size = i;

    //sort the elements in ascending order from index [0,i - 1]
    for(int k = 0; k < size; k++){
        for(int j = k + 1; j < size; j++){
            if(array[k] > array[j]){
                temp = array[k];
                array[k] = array[j];
                array[j] = temp;
            }
        }
    }

    //printing after sorting
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

   for (int i = 0; i < number; i++){
        scanf("%d", array + i);
   }
    //combination_Of_Four(array, number, 37);
    sort_In_Range(array, number);

    // printUnique(array, number);
    // printf("\nThe number of inversions that can be formed is %d.",count_Inversions(array, number));
    // printf("The Maximum difference between two elements in the array is:%d",maximum_Difference(array, number));
    // Free the allocated memory
   free(array);

   return 0;
}