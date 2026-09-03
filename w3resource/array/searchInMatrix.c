/*find the element in a sorted row and columns matrix*/

#include <stdio.h>
#include <stdlib.h>

void binarySearch(int matrix[4][4], int size, int target){

    int low, high;
    int mid = 0;

    for(int i = 0; i < size; i++){
        low = 0, high = size - 1;
        while(low <= high){
            mid = (low + high) / 2;
            if(target > matrix[i][mid]) low = mid + 1;
            else if(target < matrix[i][mid]) high = mid - 1;
            else{
                printf("Element %d found at index [%d][%d].",target, i, mid);
                return;
            }
        }
    }
    printf("Element %d not found.",target);
}

int main() {
    
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int target = 11;

    binarySearch(matrix, 4, target);

   return 0;
}