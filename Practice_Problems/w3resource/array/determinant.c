/*finding the determinant of 3 x 3 matrix*/
#include <stdio.h>
#include <stdlib.h>

#define row 3
#define column 3

//function to calculate the determinant of 2x2 matrix
int determinant(int r, int c, int **matrix){

    int k = 0;
    //allocating 16 bytes memory for 2 x 2 matrix 
    int *dupliMatrix=(int *)malloc(4 * sizeof(int));
    if(dupliMatrix == NULL){
        perror("Error while allocating the memory.");
        exit(EXIT_FAILURE);
    }

    //finding the 2x2 matrix elements
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            //storing the element if they dont fall under the same row and column
            if( i != r && j != c){  
                dupliMatrix[k++]=matrix[i][j];
            }
        }
    }   
    int det=(dupliMatrix[0] * dupliMatrix[3]) - (dupliMatrix[1] * dupliMatrix[2]);
    free(dupliMatrix);
    //returning the determinant of the found matrix
    return det; 

}

int main() {

    //step 1:allocating memory for a 3 x 3 matrix
   int **matrix = (int **)malloc(row * sizeof(int *));

   if (matrix == NULL) {
        perror("Error while allocating the memory");
        exit(1);
   }

    //allocating the memory for the blocks for each 1D arrays in 2D array
    for(int i = 0; i < row;i++){
        matrix[i]=(int *)malloc(column * sizeof(int));
        if(matrix == NULL){
            perror("Error while allocating the memory.");
            exit(EXIT_FAILURE);
        }
    }

    //step 2: taking input 
    printf("Enter the elements in the matrix:\n");
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            scanf("%d",*(matrix + i) + j);
        }
    }

    int r=0,c=0;    //index of the elements of first row
    int det[3]; //1D array to store the 3 determinants of 2 x 2 matrix

    //only c will increase as row will be same but column will be different
    while(c < 3){
    det[c]=determinant(r, c, matrix);
    c++;
    }

    //final step
    //finding the determinant using the formula
    printf("Determinant of 3 x 3 matrix is %d",(matrix[0][0] * det[0]) - (matrix[0][1] * det[1]) + (matrix[0][2] * det[2]));

    // freeing allocated memory
    for(int i = 0; i < row; i++){
        free(matrix[i]);
    }
    // Free the allocated memory
   free(matrix);

   return 0;
}