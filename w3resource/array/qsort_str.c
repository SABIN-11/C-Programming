//sorting strings using quicksort algorithm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to swap the two strings
// void swap(char *str1, char *str2){

//     char *temp = malloc(30 * sizeof(char)); //allocating memory for the temporary string temp
//     strcpy(temp, str1); //copy the str1 string into temp
//     strcpy(str1, str2); //copy the str2 stirng into str1
//     strcpy(str2, temp); //copy the temp i.e str1 into str2

//     free(temp); //free the allocated memory for the temp string
// }

// //function to divide an array into two subarrays from the pivot element
// int partition(char **string, int low, int high){

//     char *pivot = malloc(30 * sizeof(char));    //allocating memory for the pivot string
//     strcpy(pivot, string[high]);    //make the last string the pivot
//     int swapping_index = low;   //index to swap the elements with

//     for(int i = low; i < high; i++){    //from low to high - 1

//         if(strcmp(string[i], pivot) < 0){   //comparing which string comes first alphabetically
//             //if string[i] comes before pivot string
//             swap(string[i], string[swapping_index]);    //swap the current index string with the swapping index string
//             swapping_index++;   //then increase the swapping index
//         }
        
//     }

//     swap(string[high], string[swapping_index]); //swap the pivot string with the swapping index string
//     //now the pivot is in its right position

//     free(pivot);    //free the allocated memory for the pivot string
//     return swapping_index;  //return the final position of the pivot to know the 2 subarrays
// }

// //recursive function to sort the array using quicksort algorithm
// void quicksort(char **string, int low, int high){

//     if(low < high){ //low and high indexes 

//         int pivot_position = partition(string, low, high);  //divide the array into 2 subarrays from the pivot element
//         quicksort(string, low, pivot_position - 1); //sorting of the left subarray
//         quicksort(string, pivot_position + 1, high);    //sorting of the right subarray

//     }
//     else{   //base case low >= high
//         return; //return back once low >= high
//     }

// }

int compare(const void *str1, const void *str2){
    
    // Cast the pointers to char pointers
    const char *s1 = *(const char **)str1; // Dereference to get the actual string
    const char *s2 = *(const char **)str2; // Dereference to get the actual string
    
    // Use strcmp to compare the strings
    return strcmp(s1, s2);

}

int main() {

    char **string = malloc(7 * sizeof(char *));
    for (int i = 0; i < 7; i++) {
        string[i] = malloc(30 * sizeof(char));
    }
    //assign values to the 2d array of characters
    strcpy(string[0], "grape");
    strcpy(string[1], "elderberry");
    strcpy(string[2], "cherry");
    strcpy(string[3], "finland");
    strcpy(string[4], "banana");
    strcpy(string[5], "date");
    strcpy(string[6], "apple");


    // quicksort(string, 0, 6);
    qsort(string, 7, sizeof(char *), compare);

    for(int i = 0; i < 7; i++){
        printf("%s\n", string[i]);
        free(string[i]);    //free the strings inside the 2D array
    }

    free(string);

    return 0;
}