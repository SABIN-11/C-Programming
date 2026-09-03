/*multiplication of matrices using dynamic memory allocation*/
#include <stdio.h>
#include <stdlib.h>

int main() {
   int rows,cols,rows2,cols2;

    printf("Enter the number of rows and columns you want in the first matrix: ");
    scanf("%d%d",&rows,&cols);
    printf("Enter the number of rows and columns you want in the second matrix: ");
    scanf("%d%d",&rows2,&cols2);

    if(cols == rows2){
   //allocate memory for array of pointers/multiple 1D arrays
    int **array=(int **)calloc(rows, sizeof(int *));

    if (array == NULL) {
        perror("Error while allocating the memory");
        exit(1);
    }

    //allocating memory for all the columns/blocks inside the pointer/array
    for(int i = 0; i < rows; i++){
    array[i]=(int *)calloc(cols,sizeof(int)); //as for addition of matrices rows and columns must be same
    }

    //take input elements
    printf("Enter elements for matrix A:");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            scanf("%d",*(array + i) + j);
        }
    }
       //allocate memory for array of pointers/multiple 1D arrays
   int **array_2=(int **)calloc(rows2, sizeof(int *));

   if (array_2 == NULL) {
        perror("Error while allocating the memory");
        exit(1);
   }

    //allocating memory for all the columns/blocks inside the pointer/array
   for(int i = 0; i < rows2; i++){
    array_2[i]=(int *)calloc(cols2,sizeof(int)); //as for addition of matrices rows and columns must be same
   }

    //take input elements
    printf("Enter elements for matrix B:");
    for(int i = 0; i < rows2; i++){
        for(int j = 0; j < cols2; j++){
            scanf("%d",*(array_2 + i) + j);
        }
    }
    int sum;
    printf("Matrix after multiplication:\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols2; j++){
            sum=0;
            for(int k = 0; k < cols2; k++){
                sum = sum + array[i][k] * array_2[k][j];
            }
            printf("%d\t",sum);
        }
        printf("\n");
    }

    // Free the allocated memory
    free(array);
    free(array_2);
    }

    else
    printf("Matrix multiplication is not possible");

   return 0;
}