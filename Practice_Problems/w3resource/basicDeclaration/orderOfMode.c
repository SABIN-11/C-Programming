/*ordering the elements in terms of their frequency*/

#include<stdio.h>
#include<stdbool.h>

void orderOfMode(int numberOfTerms){

    int array[numberOfTerms];
    int frequency[numberOfTerms];
    bool is_unique[numberOfTerms];

    printf("Input the terms in the sequence:");
    
    for(int i = 0; i < numberOfTerms; i++){

        scanf("%d",&array[i]);
        frequency[i]=1; //frequency is 1 for every element
        is_unique[i]=true;  //assigning true to every element

    }

    //counting the frequency of each elements
    for(int i = 0; i < numberOfTerms; i++){

        if(is_unique[i]){

            for(int j = i + 1; j < numberOfTerms; j++){

                if(array[i] == array[j]){

                    frequency[i]++;
                    is_unique[j]=false; //assigning false to same elements 

                }

            }
        }
    }

    int tempFreq, tempArray;

    //to move the higher frequency elements above in the array
    for(int i = 0; i < numberOfTerms; i++){

        if(is_unique[i]){

            for(int k = i + 1; k < numberOfTerms; k++){

                if(frequency[i] < frequency[k]){

                    //swapping the frequency
                    tempFreq=frequency[i];
                    frequency[i]=frequency[k];
                    frequency[k]=tempFreq;

                    //swapping the elements along with the frequency
                    tempArray=array[i];
                    array[i]=array[k];
                    array[k]=tempArray;

                }
            }
        }

    }

    printf("Mode values of the array in ascending order:\n");

    for(int i = 0; i < numberOfTerms; i++){

        if(is_unique[i])
        printf("%d\n",array[i]);

    }
}

int main(){

    int numberOfTerms;

    printf("Enter the number of terms:");
    scanf("%d",&numberOfTerms);

    orderOfMode(numberOfTerms);

    return 0;
}


// #include <stdio.h>
// #include <stdbool.h>

// // Function to calculate and print the mode values
// void orderOfMode(int numberOfTerms) {
//     int array[numberOfTerms];
//     int frequency[numberOfTerms];
//     bool is_unique[numberOfTerms];

//     printf("Input the terms in the sequence:\n");

//     // Initialize arrays
//     for (int i = 0; i < numberOfTerms; i++) {
//         scanf("%d", &array[i]);
//         frequency[i] = 1;   // Frequency is 1 for every element
//         is_unique[i] = true;  // Mark all elements as unique initially
//     }

//     // Counting the frequency of each element
//     for (int i = 0; i < numberOfTerms; i++) {
//         if (is_unique[i]) {
//             for (int j = i + 1; j < numberOfTerms; j++) {
//                 if (array[i] == array[j]) {
//                     frequency[i]++;
//                     is_unique[j] = false; // Mark duplicates as non-unique
//                 }
//             }
//         }
//     }

//     // Sort the array by frequency (descending) and by value (ascending)
//     for (int i = 0; i < numberOfTerms - 1; i++) {
//         for (int j = i + 1; j < numberOfTerms; j++) {
//             if (is_unique[i] && is_unique[j]) {
//                 if (frequency[i] < frequency[j] || (frequency[i] == frequency[j] && array[i] > array[j])) {
//                     // Swap frequency
//                     int tempFreq = frequency[i];
//                     frequency[i] = frequency[j];
//                     frequency[j] = tempFreq;

//                     // Swap elements
//                     int tempArray = array[i];
//                     array[i] = array[j];
//                     array[j] = tempArray;
//                 }
//             }
//         }
//     }

//     printf("Mode values of the array in ascending order:\n");

//     // Print mode values
//     for (int i = 0; i < numberOfTerms; i++) {
//         if (is_unique[i] && frequency[i] > 1) { // Only print elements with frequency > 1
//             printf("%d\n", array[i]);
//         }
//     }
// }

// int main() {
//     int numberOfTerms;

//     printf("Enter the number of terms: ");
//     scanf("%d", &numberOfTerms);

//     if (numberOfTerms > 0) {
//         orderOfMode(numberOfTerms);
//     } else {
//         printf("Number of terms must be greater than 0.\n");
//     }

//     return 0;
// }
