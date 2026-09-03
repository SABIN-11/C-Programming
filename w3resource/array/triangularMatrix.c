/*setting zeros in the lower and upper triangular matrix*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

//function for lower triangular matrix
void lowerTriangle(int **matrix, int rows, int cols){

    for(int i = 0; i < rows; i++){
        for(int j = 0; i != j; j++){
            matrix[i][j] = 0;
        }
    }

    //printing the matrix with lower triangle set to zero's
    for(int i = 0; i < rows; i++){
        for(int j = 0; j <cols; j++){
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
}

//function for upper triangular matrix
void upperTriangle(int **matrix, int rows, int cols){

    for(int i = 0; i < rows - 1; i++){
        for(int j = i + 1; j < cols; j++){
            matrix[i][j] = 0;
        }
    }

    //printing the matrix with upper triangle set to zero's
    for(int i = 0; i < rows; i++){
        for(int j = 0; j <cols; j++){
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }

}
int main(void){
    int rows,cols;
    
    //asking for the rows and columns of the matrix
    printf("Enter the rows and columns of the matrix:");
    scanf("%d%d",&rows,&cols);

    //allocating memory for the arrays
    int **matrix=(int **)malloc(rows * sizeof(int *));

    if(matrix == NULL){
        perror("Error while allocating the memory.");
        exit(EXIT_FAILURE);
    }
    //allocating the memory for the blocks for each 1D arrays in 2D array
    for(int i = 0; i < rows;i++){
        matrix[i]=(int *)malloc(cols * sizeof(int));
        if(matrix == NULL){
            perror("Error while allocating the memory.");
            exit(EXIT_FAILURE);
        }
    }

    //taking input 
    printf("Enter the elements in the matrix:\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            scanf("%d",*(matrix + i) + j);
        }
    }
    
    char choice;
    printf("Do you want to set zeros for lower or upper matrix? Press 'L' or 'l' for lower or 'U' or 'U' for upper matrix:");
    getchar(); // to consume the newline character left by previous scanf
    scanf("%c",&choice);

    if(tolower(choice) == 'l')
    lowerTriangle(matrix, rows, cols);

    else if(tolower(choice) == 'u')
    upperTriangle(matrix, rows, cols);

    else
    printf("Invalid choice entered. Enter(L,l or U,u)");

    // freeing allocated memory
    for(int i = 0; i < rows; i++){
        free(matrix[i]);
    }
    free(matrix);

    return 0 ;
}