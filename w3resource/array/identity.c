/*checking if a matrix is an identity matrix or not*/
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

bool isIdentityMatrix(int **matrix, int size){

    bool flag=true; //to keep track of the correctness in the matrix

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){

            //if it is the main/principle diagonal
            if(i == j){
                if(matrix[i][j] != 1){
                    flag=false;
                    break;
                }
            }

            else{
                if(matrix[i][j] != 0){
                    flag=false;
                    break;
                }
            }
        }
    }

    return flag;

}

int main() {
   
   /*condition for identity matrix : matrix must me square matrix i.e row=column so only one input is enough*/
   int size;

   printf("Enter the size of the matrix: ");
   scanf("%d", &size);

    //step 1:allocating memory for the matrix
   int **matrix = (int **)malloc(size * sizeof(int *));

   if (matrix == NULL) {
        perror("Error while allocating the memory");
        exit(1);
   }

   for (int i = 0; i < size; i++){
    matrix[i] = (int *)malloc(size * sizeof(int));
    if(matrix[i] == NULL){
        perror("Error while allocating the memory");
        exit(1);
    }
   }

    //step 2:take input for the matrix
    printf("Enter the elements:\n");
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            scanf("%d",&matrix[i][j]);
        }
    }

    //step 3:call the function for the checking
    if(isIdentityMatrix(matrix, size))
    printf("It is identity matrix.");

    else
    printf("It is not identity matrix.");

    // step 4:Free the allocated memory
    for(int i = 0; i < size; i++){
        free(matrix[i]);
    }
   free(matrix);

   return 0;
}