/*finding the sum of the right diagonals of a square matrix*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows,cols;

    printf("Enter the number of rows and columns you want in the first matrix: ");
    scanf("%d%d",&rows,&cols);

    //allocating memory for the number of arrays
   int **array = (int **)malloc(rows * sizeof(int *));

   if (array == NULL) {
        perror("Error while allocating the memory");
        exit(1);
   }
    //allocating memory for the blocks in each array
   for(int i = 0; i < rows; i++){
    array[i] = (int *)malloc(cols * sizeof(int));
   }
    if (array == NULL) {
        perror("Error while allocating the memory");
        exit(1);
    }
    //taking input
    printf("Enter the elements:\n");
   for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
        scanf("%d",&array[i][j]);
    }
   }

    //finding the sum of the right diagonals
    int sum_R = 0;
    int j = cols - 1;

    for(int i = 0; i < rows; i++){
        sum_R += array[i][j--];
    }

    //finding the sum of left diagonals
    int sum_L=0,k=0;
    for(int i = 0; i < rows; i++){
        sum_L+=array[i][k++];
    }
    printf("Sum of right diagonals is %d.",sum_R);
    printf("\nSum of left diagonals is %d.",sum_R);

    //sum of rows and columns
    printf("\nRow Sum\n");
    int sum;
    for(int i = 0; i < rows; i++){
        sum=0;
        for(int j = 0; j < cols; j++){
            sum+=array[i][j];
        }
        printf("%d",sum);
        printf("\n");

    }
    printf("Column Sum\n");
    for(int j = 0; j < cols; j++){
        sum=0;
        for(int i = 0; i < rows; i++){
            sum+=array[i][j];
        }
        printf("%d",sum);
        printf("\n");
    }
    // Free the allocated memory
   free(array);

   return 0;
}