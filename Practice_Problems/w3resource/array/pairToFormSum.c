/*find the pair of elements which can form a given sum*/
#include <stdio.h>
#include <stdlib.h>

//function to find the pair of elements that can add up to a given sum
void findPair(int *array, int number, int sumToFind){
    // int s;

    printf("The array is :\t");
    for(int i = 0; i < number; i++)
    printf("%d\t",array[i]);

    printf("\nSum to find : %d",sumToFind);

    //compare every element with each other using nested loop
    printf("\nPair of elements which can form %d is given below:\n",sumToFind);
    for(int i = 0; i < number; i++){
        for(int j = i + 1; j < number; j++){
            // s=0;    //s is 0 through every j because we only check pairs 
            if(array[i] + array[j] == sumToFind){
                printf("[%d] + [%d] : %d + %d = %d\n",i , j, array[i], array[j], sumToFind);
                break;
            }
        }
    }
}

//function to find the majority element in an array
//majority element the element which occurs more than size/2 of the array
void findMajority(int *array, int number, int largest){
    //allocate memory for the frequency array to store the frequncy of the elements upto largest
    int *freq = (int *)malloc(sizeof(int) * (largest + 1));
    if(freq == NULL){
        perror("Error while allocating the memory");
        exit(1);
    }

    for(int i = 0; i <= largest; i++)
    freq[i] = 1;   //initializing each elements frequency 1

    //compare each element with one another to find duplicates if there are any
    for(int i = 0; i < number; i++){
        for(int j = i + 1; j < number; j++){
            if(array[i] == array[j]){
                freq[array[i]]++;
                break;
            }
        }
    }

    int check=0;
    //check if any frequency is greater than number/2
    for(int i = 0; i <= largest; i++){
        if(freq[i] > number / 2){
        check=i;
        break;
        }
    }

    if(check)
    printf("Majority element is : %d\n",check);

    else
    printf("There is no majority element.");

    free(freq);

}

//function to find the odd occuring element
void findOddOccuringElement(int *array, int number, int largest){
    //allocate memory for the frequency array to store the frequncy of the elements upto largest
    int *freq = (int *)malloc(sizeof(int) * (largest + 1));
    if(freq == NULL){
        perror("Error while allocating the memory");
        exit(1);
    }

    for(int i = 0; i <= largest; i++)
    freq[i] = 1;   //initializing each elements frequency 1

    //compare each element with one another to find duplicates if there are any
    for(int i = 0; i < number; i++){
        for(int j = i + 1; j < number; j++){
            if(array[i] == array[j]){
                freq[array[i]]++;
                break;
            }
        }
    }

    //check if the count is odd
    for(int i = 0; i <= largest; i++){
        if(freq[i] % 2 != 0 && freq[i] > 1){
            printf("Element occuring odd number of times is %d.",i);
            break;
        }
    }

    free(freq);

}

//function to find the largest contigious subarray using kadane's algorithm
void largestSum(int *array, int number){
    
    int largest=0,sum=0;
    for(int i = 0; i < number; i++){
        sum+=array[i];

        if(sum > largest){
            largest = sum;
        }
        if(sum < 0){
            sum=0;
        }

    }

    printf("Largest sum of contigious subarray is %d.",largest);

}

//finding the pivot element in the array using binary search
void pivotElement(int *array, int number){

    int start = 0,end = number - 1;

    while(start <= end){   //while true
        int mid = (start + end) / 2;    //finding the median index

        if((mid == 0 || array[mid] > array[mid - 1]) && (mid == number - 1 || array[mid] > array[mid +1])){
            printf("Pivot element is %d.",array[mid]);
            break;
        }
        // else if(array[mid - 1] > array[mid + 1]){
        //     end = mid;
        // }
        // else if(array[mid + 1] > array[mid - 1]){
        //     start = mid;
        // }

        if (array[mid] >= array[start]) {
        start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

}

int main(void) {
   int number,sumToFind,largest=0;

   printf("Enter the number of elements you want in the array: ");
   scanf("%d", &number);
//    printf("\nEnter the sum to find:");
//    scanf("%d",&sumToFind);

   int *array = (int *)malloc(number * sizeof(int));

   if (array == NULL) {
        printf("Error while allocating the memory");
        exit(1);
   }

    printf("Enter the elements:\n");
   for (int i = 0; i < number; i++){
    scanf("%d", array + i);
    if(*(array + i) > largest)  largest=*(array + i);
   }

    // findPair(array, number, sumToFind);
    // findMajority(array, number, largest);
    // findOddOccuringElement(array, number,largest);
    // largestSum(array, number);
    pivotElement(array, number);

    // Free the allocated memory
   free(array);

   return 0;
}