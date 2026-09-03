/*finding the minimum element in a rotated array which was sorted before*/

#include <stdio.h>
#include <stdlib.h>

//linear approach to find the minimum element

// int minimumElement(int array[7], int size, int index){

//     // Base case: if we reach the end of the array, return the first element
//     if (index == size) return array[0];

//     if(array[index] < array[index - 1]) return array[index];
//     return minimumElement(array, size, index + 1);
// }

//binary search to find the minimum element

int minimum_Binary(int array[10], int start, int end){

    if(start == end)    return array[start];

    //find the mid element
    int mid = (start + end) / 2;
    //if the mid element is greater than the end element, then the minimum element must be in right
    if(array[mid] > array[end]) return minimum_Binary(array, mid + 1, end);

    //if the mid element is smaller than the end element, then the minimum element must be in left
    else if(array[mid] < array[end]) return minimum_Binary(array, start, mid);
    
}
int main() {

    int array[10] = {6,7,8,9,10,1,2,3,4,5};
    int size = sizeof(array) / sizeof(array[0]);

    // int min = minimumElement(array, size, 1);
    // printf("Minimum element is %d.",min);
    printf("Minimum element is %d.",minimum_Binary(array, 0, size - 1));

    return 0;
}