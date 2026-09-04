// i+1 element must be triple of i

#include<stdio.h>

int main(){

    int array[5];

    printf("Enter the first array element:");
    scanf("%d",&array[0]);

    printf("n[0]:%d",array[0]);

    for(int i = 1; i < 5; i++)
    printf("\nn[%d]:%d",i,array[i]=array[i-1] * 3);

    return 0;
}