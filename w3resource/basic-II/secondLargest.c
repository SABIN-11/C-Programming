/*take n integers and find the second largest integer*/

#include<stdio.h>
#include<limits.h>

int secondLargest(int limit){

    int largest,S_largest;
    int integers;

    largest=S_largest=INT_MIN;  //assigning the lowest value to largest and second largest
    
    printf("Enter %d integers:\n",limit);

    for(int i = 0; i < limit; i++){

        scanf("%d",&integers);

        //changing the largest and second largest if entered integer is larger
        if(integers > largest){
            S_largest=largest;
            largest=integers;
        }

        else if(integers > S_largest && integers != largest)
        S_largest=integers;

    }

    return S_largest;
}

int main(){

    int limit;
    printf("Enter how many integers do you want to input:");
    scanf("%d",&limit); //limit for how many inputs

    printf("The second largest integer among the entered ones is %d",secondLargest(limit));


    return 0;
}