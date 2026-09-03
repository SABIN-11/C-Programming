/*find the maximum sum of a contiguous subsequence from a given sequence of numbers a1, a2, a3, ... an ( n = number of terms in the sequence).
Input:
You can assume that 1 <= n <= 500 and -10000 <= ai <= 10000.*/

#include<stdio.h>
#include<limits.h>

//using kadane's algorithm

int maximumSum(int numberOfTerms, int sequence[numberOfTerms]){

    int maximum=INT_MIN;
    int currentSum=0;

    for(int i = 0; i < numberOfTerms; i++){

        currentSum+=sequence[i];

        if(currentSum > maximum)
        maximum=currentSum;

        if(currentSum < 0)
        currentSum=0;
        
    }


    return maximum;
}

int main(){

    int numberOfTerms;

    printf("Enter the number of terms:");
    scanf("%d",&numberOfTerms);

    //base case for error of number of terms
    if(numberOfTerms < 1 || numberOfTerms > 500){

        printf("ERROR! Number of terms exceeds the range i.e 1-500");
        return 1;

    }

    int sequence[numberOfTerms];

    printf("Input the terms in the sequence:");
    
    for(int i = 0; i < numberOfTerms; i++){

        scanf("%d",&sequence[i]);

            //base case for values i.e ai
        if(sequence[i] < -10000 || sequence[i] > 10000){

            printf("ERROR! The value exceeds the range i.e -10000 - 10000");
            return 1;

        }

    }

    printf("Maximum sum of contigious subsequence is %d.",maximumSum(numberOfTerms, sequence));
    return 0;
}

// #include<stdio.h>
// #include<limits.h>

// int main(){

//     int numberOfTerms;

//     printf("Enter the number of terms in the sequence:");
//     scanf("%d",&numberOfTerms);

//     //base case for error
//     if(numberOfTerms < 1 || numberOfTerms > 500){

//         printf("ERROR! Number of terms exceeds the range i.e 1-500");
//         return 1;

//     }

//     int sequence[numberOfTerms];

//     printf("Input the terms in the sequence:");
    
//     for(int i = 0; i < numberOfTerms; i++){

//         scanf("%d",&sequence[i]);
        
//         if(sequence[i] < -10000 || sequence[i] > 10000){

//             printf("ERROR! The value exceeds the range i.e -10000 - 10000");
//             return 1;

//         }

//     }

//     int maximumSum=INT_MIN; //assigning the lowest value to maximumSum
//     int totalSequence= ( numberOfTerms * (numberOfTerms + 1) ) / 2; //calculating the no of total sequence by using n(n+1)/2 formula
//     int sum;

//     for(int i = 0; i < totalSequence; i++){

//         for(int j = i; j < numberOfTerms; j++){
            
//             sum=0;

//             for(int k = i; k <= j; k++){

//                 sum+=sequence[k];

//             }

//             if(sum > maximumSum)
//             maximumSum=sum;

//         }

//     }

//     printf("Maximum sum of the contigious subsequence is %d.",maximumSum);

//     return 0;
// }


