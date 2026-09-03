/*take 3 inputs A,B and X. Find the smallest absolute difference between X and the integers in the range [A,B]*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int absoluteDifference(int lower, int upper, int differentiator){

    int diff1=abs(differentiator - lower);
    int diff2=abs(differentiator - upper);

    return (diff1 > diff2)?diff2:diff1;
    
}
int main(){

    int A,B,X;
    printf("Enter 3 integers(A,B,X):");
    scanf("%d%d%d",&A,&B,&X);

    printf("The smallest absolute difference between X and the integers between the range of A to B is %d",absoluteDifference(A, B, X));

    return 0;
}