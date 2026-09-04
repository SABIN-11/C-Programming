//sorting an array using quicksort algorithm

#include <stdio.h>
#include <stdlib.h>

// void swap(int *num1, int *num2){

//     int temp = *num1;
//     *num1 = *num2;
//     *num2 = temp;

// }

// int partition(int arr[], int low, int high){

//     int pivot = arr[high];
//     int swapping_index = low;

//     for(int i = low; i < high; i++){
//         if(arr[i] < pivot){
//             swap(arr + i, arr + swapping_index);
//             swapping_index++;
//         }
//     }

//     swap(arr + high, arr + swapping_index);

//     return swapping_index;
// }

// void quicksort(int arr[], int low, int high){

//     if(low < high){

//         int pivot_position = partition(arr, low, high);
//         quicksort(arr, low, pivot_position - 1);
//         quicksort(arr, pivot_position + 1, high);

//     }
//     else{
//         return;
//     }

// }

int compare(const void *a, const void *b){

    return *(const int *)a - *(const int *)b;
    
}

int main() {

    int arr[] = {5, 2, 8, 1, 9, 14, 12, 11, 19, 1, 4, 3};

    int size = sizeof(arr) / sizeof(arr[0]);
    // quicksort(arr, 0, size - 1);
    qsort(arr, size, sizeof(int), compare);


    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}