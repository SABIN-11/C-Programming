
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//function to find the minimum swaps to make a contigious subarray containing elements <= k
//using window sliding approach

int min_Swaps(int *array, int size, int k){

    //step 1:find how many elements are less than or equal to k
    int num_less_k = 0;
    for(int i = 0; i < size; i++)
        if(array[i] <= k)   num_less_k++;

    //step 2:form subarrays of num_less_k elements and find how many elements in that subarray is <= k
    int temp = num_less_k;
    int i = 0, count;
    int max_count = INT_MIN;

    while(i < size){
        count = 0;
        num_less_k = temp;
        while(num_less_k >= 1){
            if(array[i] <= k)   count++;
            i++,num_less_k--;
        }
        i = i - temp + 1;

        if(count > max_count)   max_count = count;
    }

    return temp - max_count;
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

    printf("The minimum number of swaps required is %d.",min_Swaps(array, number, 35));

    // Free the allocated memory
   free(array);

   return 0;
}