/*adding two matrices of same size using dynamic memory allocation*/
#include <stdio.h>
#include <stdlib.h>

int main() {
   int rows;

   printf("Enter the number of rows you want in the array: ");
   scanf("%d", &rows);

   //allocate memory for array of pointers/multiple 1D arrays
   int **array=(int **)calloc(rows, sizeof(int *));

   if (array == NULL) {
        perror("Error while allocating the memory");
        exit(1);
   }

    //allocating memory for all the columns/blocks inside the pointer/array
   for(int i = 0; i < rows; i++){
    array[i]=(int *)calloc(rows,sizeof(int)); //as for addition of matrices rows and columns must be same
   }

    //take input elements
    printf("Enter elements for matrix A:");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < rows; j++){
            scanf("%d",*(array + i) + j);
        }
    }

       //allocate memory for array of pointers/multiple 1D arrays
   int **array_2=(int **)calloc(rows, sizeof(int *));

   if (array_2 == NULL) {
        perror("Error while allocating the memory");
        exit(1);
   }

    //allocating memory for all the columns/blocks inside the pointer/array
   for(int i = 0; i < rows; i++){
    array_2[i]=(int *)calloc(rows,sizeof(rows)); //as for addition of matrices rows and columns must be same
   }

    //take input elements
    printf("Enter elements for matrix B:");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < rows; j++){
            scanf("%d",*(array_2 + i) + j);
        }
    }
    int sum=0;
    //add two matrices
    printf("Matrix after addition:\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < rows; j++){
            sum=(*(*(array + i) + j)) + (*(*(array_2 + i) + j));
            printf("%d\t",sum);
        }
        putc('\n',stdout);
    }
   

    // Free the allocated memory
   free(array);
   free(array_2);

   return 0;
}