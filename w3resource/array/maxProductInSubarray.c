/* find the maximum product subarray in a given array*/
#include <stdio.h>
#include <stdlib.h>

// int maxProduct(int *array, int size, int index, int negativeProd, int positiveProd, int max_Prod){

//     if(index >= size)   return max_Prod;

//     if(array[index] == 0)   negativeProd = positiveProd = 1;    //if element is 0 restart again
//     else if(array[index] < 0)   negativeProd *= array[index];   //store negative product
//     else   positiveProd *= array[index];    //store positive product

//     int prod = negativeProd * positiveProd;

//     if(prod > max_Prod) max_Prod = prod;
    
//     return maxProduct(array, size, index + 1, negativeProd, positiveProd, max_Prod);
// }

void equalZeroOne(int *array, int size){
    int countZero = 0, countOne = 0;
    int length = 0, max_Length = 0;//TO CALCULATE THE LENGTH OF THE SUBARRAY
    int low = -1, high = -1;//AREA OF THE SUBARRAY

    for(int i = 0; i < size; i++){
        countZero = countOne = 0;
        for(int j = i; j < size; j++){
            if(array[j] == 0)   countZero++;
            else if(array[j] == 1)  countOne++;

            if(countOne == countZero){
                length = j - i + 1; //calculating the length of the subarray
                if(length > max_Length){
                    max_Length = length;
                    low = i;
                    high = j;
                }
            }
        }
    }
    
    if(low != -1 && high != -1) 
        printf("Largest Subarray having equal 0's and 1's found from index %d to %d.\n", low, high);
    else
        printf("No subarray found with an equal number of 0's and 1's.\n");
}

int main() {
   int number;

   printf("Enter the number of elements you want in the array: ");
   scanf("%d", &number);

   int *array = (int*)malloc(number * sizeof(int));

   if (array == NULL) {
        printf("Error while allocating the memory");
        exit(1);
   }

   for (int i = 0; i < number; i++)
        scanf("%d", array + i);

    // printf("Max product of the subarray is %d.",maxProduct(array, number, 0, 1, 1, 0));
    equalZeroOne(array, number);
    // Free the allocated memory
   free(array);

   return 0;
}