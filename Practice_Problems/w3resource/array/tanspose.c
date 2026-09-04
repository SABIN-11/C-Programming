/*finding the transpose of a matrix*/
#include <stdio.h>
#include <stdlib.h>

int main() {
   
   int rows,cols;

    printf("Enter the number of rows and columns you want in the first matrix: ");
    scanf("%d%d",&rows,&cols);
   
   //allocating memory for the number of arrays
   int **array=(int **)malloc(rows * sizeof(int *));
   if (array == NULL) {
        perror("Error while allocating the memory");
        exit(1);
   }

   //allocating memory for the columns/blocks in the array
   for(int i = 0; i < rows; i++){
    array[i]=(int *)malloc(cols * sizeof(int));
   }

    //taking input 
    printf("Enter the elements in the matrix:\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            scanf("%d",*(array + i) + j);
        }
    }

    //transposing the matrix
    printf("After transposing:\n");
    for(int i = 0; i < cols; i++){
        for(int j = 0; j < rows; j++){
            printf("%d\t",array[j][i]);
        }
        printf("\n");
    }

    // Free the allocated memory
   free(array);

   return 0;
}