/*finding the row index with the maximum 1's*/

#include <stdio.h>
#include <stdlib.h>

int maximum_One(int matrix[5][5], int rowCol){
    int count_1;
    int max_1 = -1;
    int index;
    //counting the no of 1 in each row
    for(int i = 0; i < rowCol; i++){
        count_1 = 0;
        for(int j = 0; j < rowCol; j++){
            if(matrix[i][j] == 1){
                count_1++;
            }
        }
        if(count_1 > max_1){
            max_1 == count_1;
            index = i;
        }
    }
    return index;
}

int main() {

    int matrix[5][5] = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 1, 1},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 0, 1}
    };

    printf("Index having maximum no of 1's is %d.",maximum_One(matrix, 5));

   return 0;
}