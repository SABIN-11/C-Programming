/*add row and column values to make an extra row and column*/

#include<stdio.h>

void printTable(int size, int TABLE[size+1][size+1], int sum){

    for(int k = 0; k <= size; k++){

        sum=0;

        for(int j = 0; j < size; j++){

            sum+=TABLE[j][k];   //computing the column sum 

        }
        TABLE[size][k]=sum; //assigning the column sum to last row columns 
    }

    for(int i = 0; i <= size; i++){

        for(int j = 0; j <= size; j++){

            printf("%d\t",TABLE[i][j]);

        }
        printf("\n");
    }

}

int main(){

    int size;
    printf("Input number of rows/columns:");
    scanf("%d",&size);

    int TABLE[size+1][size+1];
    int sum;

    printf("Input the cell value\n");

    //entering the values
    for(int i = 0; i < size; i++){
        
        sum=0;
        printf("Row %d input cell values\n",i);

        for(int j = 0; j < size; j++){

            scanf("%d",&TABLE[i][j]);
            sum+=TABLE[i][j];   //taking the row sum upto n-1

        }

        TABLE[i][size]=sum; //assigning the row sum to n
    }

    printTable(size,TABLE, 0);


    return 0;
}

