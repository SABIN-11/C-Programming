
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWCOL 4

//function to find the sum of the upper triangle of the matrix
int sum_Of_UpperTriangle(int matrix[4][4]){

    int sum = 0;
    
    for(int i = 0; i < MAX_ROWCOL; i++){
        for(int j = 0; j < MAX_ROWCOL; j++){
            if(j > i) sum += matrix[i][j];
        }
    }

    return sum;
}

int main() {

    int martrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    printf("The sum of the upper triangle of the matrix is %d.",sum_Of_UpperTriangle(martrix));

    return 0;
}