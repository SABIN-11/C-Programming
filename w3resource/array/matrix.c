/*printing a matrix using dynamic memory allocation*/
#include <stdio.h>
#include <stdlib.h>

int main() {
   int row,cols;

    printf("Enter the row and column count:");
    scanf("%d%d",&row,&cols);
   
   //allocating memory for 2d array
   //allocating memory for array of pointers
   int **array=(int **)malloc(row * sizeof(int *));

   if (array == NULL) {
        printf("Error while allocating the memory");
        exit(1);
   }

    // Allocate memory for each row
    for (int i = 0; i < row; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));
        if (array[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
    }

    //taking input
    printf("Enter the elements:\n");
    for(int i = 0; i < row; i++){
        for(int j = 0; j < cols; j++){
             scanf("%d",*(array + i) + j);
            // scanf("%d",&array[i][j]);
        }
    }

    //printing the matrix
    printf("Printing the %d x %d matrix:\n",row,cols);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < cols; j++){
             printf("%d\t",*(*(array + i) + j));
            // printf("%d\t",array[i][j]);
        }
        putc('\n',stdout);
    }
    // Free the allocated memory
   free(array);

   return 0;
}