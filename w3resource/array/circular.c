/*finding the maximum circular subarray sum. Circular subarray is an array that wraps the end element*/
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

// int maximumCircular(int *array, int number){

//     int max = INT_MIN;  //assingning minimum value to max
//     int start = 1;  //starting from the second element
//     int sum, count;    //to keep track of the sum of the sub arrays

//     while(start < number){
//         sum = 0;    //sum = 0 for every new start
//         count = 0;

//         for(int i = start; count <= number; i++){

//             //only check max after sub array becomes circular i.e last element is wrapped
//             if(i < start){
//                 sum+=array[i];
//                 count++;
//                 if(sum > max)   max = sum;  
//             }
//             else{
//                 sum+=array[i];
//                 count++;
//             }

//             if(i == number - 1) i = -1;  //make i = 0 once the iteration hits the last element
//         }
//         start++;    //new start 

//     }

//     return max;
// }

//using kadane's algorithm to find the maximum sum of the subarray
int kadaneMax(int *array, int number){
    int maximum = INT_MIN;
    int current_Sum = 0;
    for(int i = 0; i < number; i++){

        current_Sum+=array[i];  

        if(current_Sum > maximum){
            maximum = current_Sum;
        }

        if(current_Sum < 0){
            current_Sum = 0;
        }

    }

    return maximum;
}



int maxCircularSubarray(int *array, int number){

    int max_kadane = kadaneMax(array, number);
    int sumOfArray = 0;
    //finding the maximum sum of all elments
    for(int i = 0; i < number; i++){
        sumOfArray+=array[i];
        array[i] = -array[i];   //inverting the elements after using it
    }

    //finding the maximum sum of the subarray after inverting
    //that means the minimum sum of the subarray of the original array
    int min_Kadane = kadaneMax(array, number);
    int max_Circular = sumOfArray + min_Kadane; //maximum circular subarray is the sum of the sum of the array elments and the minimum sum of the subarray of the original array

    return  (max_kadane > max_Circular)?max_kadane:max_Circular;
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

    // printf("The maximum circular sum in the above array is:%d",maximumCircular(array, number));
    printf("The maximum circular sum in the above array is:%d",maxCircularSubarray(array, number));

    // Free the allocated memory
   free(array);

   return 0;
}
