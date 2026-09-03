/*print the elements of the matrix in the spiral form*/

#include <stdio.h>
#include <stdlib.h>

void spiralMatrix(int **matrix, int row, int column){

    int top = 0, down = row - 1, left = 0, right = column - 1;
    int direction = 0, i;

    while(top <= down && left <= right){

        if(direction == 0){ //means going right
            for(i = left; i <= right; i++){
                printf("%d ",matrix[top][i]);
            }
            top++;
        }

        else if(direction == 1){    //means going down
            for(i = top; i <= down; i++){
                printf("%d ",matrix[i][right]);
            }
            right--;
        }

        else if(direction == 2){    //means going left
            for(i = right; i >= left; i--){
                printf("%d ",matrix[down][i]);
            }
            down--;
        }

        else if(direction == 3){    //means going up
            for(i = down; i >= top; i--){
                printf("%d ",matrix[i][left]);
            }
            left++;
        }

        direction = (direction + 1) % 4;

    }
}

int main() {
   int row,column;

   printf("Enter the number of rows and columns you want in the array: ");
   scanf("%d%d", &row,&column);

   int **matrix = (int **)malloc(row * sizeof(int *));

   if (matrix == NULL) {
        perror("Error while allocating the memory");
        exit(1);
   }

    for(int i = 0; i < row; i++){
        matrix[i] = (int *)malloc(column * sizeof(int));
        if(matrix[i] == NULL){
            perror("Error while allocating the memory");
            exit(1);
        }
    }
    printf("Enter the elments:\n");
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            scanf("%d",*(matrix + i) + j);
        }
    }

    spiralMatrix(matrix, row, column);

    // Free the allocated memory
   for(int i = 0; i < row; i++){
    free(matrix[i]);
   }
   free(matrix);

   return 0;
}