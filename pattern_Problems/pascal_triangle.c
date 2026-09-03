//printing pascal's triangle with 2 ways

//header files
#include <stdio.h>
#include <stdlib.h>
#include "header_files/mathematics.h"


// //defining a macro
#define SPACE " "

//one way to do using C(n k) = n! / (n - k)! * k!

// void print_pascal_triangle(int row){
    
//     if(row == 1){
//         printf("%d\n", 1);
//         return;
//     }  
//     int coefficient = 0;

//     for(int n = 0; n < row; n++){
        
//         //print spaces
//         for(int j = n; j < row - 1; j++){
//             printf("%s",SPACE);
//         }

//         //print the coefficients using binomial coefficient theorem
//         //C (n k) = n! / (n - k)! * k!;
//         for(int k = 0; k <= n; k++){
//             coefficient = factorial(n) / (factorial(n - k) * factorial(k));
//             printf("%d ",coefficient);
//         }
//         printf("\n");
//     }

// }

//another way to do using 2 dimensional array using C(n k) = C(n - 1, k - 1) + C(n - 1, k)
void pascal_using_array(int row){
    
    //dynamically allocating memory for a 2D array
    int **pascal = (int **)malloc(row * row * sizeof(int));

    //dynamically allocating memory for 1D array inside the 2D array
    for(int i = 0; i < row; i++){
        pascal[i] = (int *)malloc(row * sizeof(int));
    }

    //printing pascal's triangle
    for(int n = 0; n < row; n++){

        //printing space
        for(int j = n; j < row - 1; j++){
            printf("%s",SPACE);
        }

        //printing the coefficients
        for(int k = 0; k <= n; k++){
            if(k == 0 || k == n){
                pascal[n][k] = 1;
            }
            else{
                pascal[n][k] = pascal[n - 1][k - 1] + pascal[n - 1][k];
            }
            printf("%d ",pascal[n][k]);
        }
        printf("\n");
    }
}

int main() {

    int row;
    printf("Enter upto how many rows you want the pascal's triangle to be.");
    scanf("%d",&row);

    // print_pascal_triangle(row);
    pascal_using_array(row);
    return 0;
}