/*find the sum of the elements before and after the maximum element*/

#include<stdio.h>

#define MAX_ITEMS 100

void beforeAfter(int array[MAX_ITEMS], int noOfItems, int largest, int largestIndex){

    int sum=0;
    //finding the largest element in the array and its position
    for(int i = 0; i < noOfItems; i++){
        if(array[i] > largest){
            largest=array[i];
            largestIndex=i;
        }
    }

    //calculating the sum before the largest index
    for(int i = 0; i < largestIndex; i++)
    sum+=array[i];

    printf("Sum of elements before largest:%d\n",sum);

    sum=0;

    //calculating the sum after the largest index
    for(int i = largestIndex+1; i < noOfItems; i++)
    sum+=array[i];

    printf("Sum of elements after largest:%d",sum);

}

int main(){

    int array[MAX_ITEMS]={0}, noOfItems;
    printf("Enter the number of items:");
    scanf("%d",&noOfItems);

    printf("Enter the elements:");
    for(int i = 0; i < noOfItems; i++)
    scanf("%d",&array[i]);

    beforeAfter(array, noOfItems, 0, 0);

    return 0;
}