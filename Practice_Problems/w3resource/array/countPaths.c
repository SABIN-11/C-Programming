
#include <stdio.h>
#include <stdlib.h>

//function to count all possible paths from top left to bottom right of a m X n matrix
//only right and down paths can be taken

int factorial(int n){

    if(n == 1)  return 1;

    return n * factorial(n - 1);
}

int count_paths(int row, int col){

    //we can use nCr formula: n! / (n - r)! * r! formula to find all the combinations of the paths

    int fact_of_n = factorial(row + col - 2);
    int fact_of_r = factorial(row - 1);
    int fact_of_diff = factorial(col - 1);

    return fact_of_n / (fact_of_r * fact_of_diff);


}

int main() {    
    int row, col;

    printf("Enter the row and column of the matrix\n");
    scanf("%d %d",&row,&col);

    int count = count_paths(row, col);
    printf("The all possible paths from top left to bottom right is:%d",count);

    return 0;
}