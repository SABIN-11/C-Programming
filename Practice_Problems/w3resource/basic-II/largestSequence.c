/*find the largest subsequence within a sequence*/

#include<stdio.h>

#define MAX_SIZE 100

void largestSubsequence(int array[MAX_SIZE], int size){

    int subSequence[MAX_SIZE];
    int k = 0;
    for(int i = 0; i < size; i++){
        //for the first element, just compare with the next element
        if(i == 0){
            if(array[i] < array[i+1]){
                subSequence[k++]=array[i];
            }
        }

        // For the last element, just compare with the previous element
        else if (i == size - 1) {
            if (array[i] > array[i - 1]) {
                subSequence[k++] = array[i];
            }
        }
        //the current index element must be smaller than before or greater than after element
        else{
            if(array[i] > array[i-1] || array[i] < array[i+1]){
                subSequence[k++]=array[i];
            }
        }
    }

    printf("Largest subsequence:");
    for(int i = 0; i < k; i++)
    printf("%d\t",subSequence[i]);


}
int main(){

    int size, array[MAX_SIZE]={0};
    printf("Enter the size of the array:");
    scanf("%d",&size);

    printf("Enter the array elements:");

    for(int i = 0; i < size; i++)
    scanf("%d",&array[i]);

    largestSubsequence(array, size);

    return 0;
}

