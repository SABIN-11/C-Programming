#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//function to find the pair of 2 numbers that forms a difference

// void find_pairs(int *array, int size, int difference){

//     int i = 0, j = 1;

//     while(i < size && j < size){

//         if(i != j && array[j] - array[i] == difference){
//             printf("The pair is (%d, %d)",array[i],array[j]);
//             return;
//         }

//         else if(array[j] - array[i] < difference)   j++;
//         else i++;

//     }
// }

//function to find the minimum distance between A and B in an array

// int min_distance(int *array, int size, int num1, int num2) {

//     int position_of_num1 = INT_MAX;
//     int position_of_num2 = INT_MAX;
//     int min_distance = INT_MAX, current_distance = 0;

//     for(int i = 0; i < size; i++){
//         if(array[i] == num1) position_of_num1 = i;  //store the position of first number
//         else if(array[i] == num2) position_of_num2 = i; //store the position of second number

//         if(position_of_num1 < size && position_of_num2 < size){ //if both numbers are found
//             current_distance = abs(position_of_num1 - position_of_num2);    //get the absolute difference of them

//             if(current_distance < min_distance) min_distance = current_distance;    //check if the difference is smaller than previous one
//         }
//     }

//     return (min_distance == INT_MAX)?-1:min_distance;   //return -1 if no pairs are found and return minimum distance

// }


//function to find the maximum distance between A and B such that array[B] > array[A]

int max_distance(int *array, int size){

    int current_max = 0, max_dis = INT_MIN;
    int pos_of_n1, pos_of_n2 = INT_MIN;

    for(int i = 0; i < size; i++){
        pos_of_n1 = i;  //position of the first element
        for(int j = i + 1; j < size; j++){
            if(array[j] > array[pos_of_n1]){    //finding the element that is greater than the first element
                pos_of_n2 = j;  //second element's position
                current_max = abs(pos_of_n2 - pos_of_n1);   //finding their absolute difference
                if(current_max > max_dis) max_dis = current_max;    //finding the maximum difference
            }
            
        }
    }
    return max_dis;
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
    // int n1 = 2, n2 = 9;

    // int min = min_distance(array, number, n1, n2);
    // if(min == -1)   printf("No pairs are found");
    // else printf("The minimum distance between %d and %d is %d.",n1, n2, min);
    printf("The maximum difference is %d",max_distance(array, number));

    // find_pairs(array, number, 53);

    // Free the allocated memory
   free(array);

   return 0;
}