/*findind all prime numbers using an algorithm*/
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

void prime(int limit){

    bool *markAsMultiplied=(bool *)malloc((limit + 1) * sizeof(bool));

    for(int i = 0; i <= limit; i++) markAsMultiplied[i]=true;

    for(int i = 2; i * i < limit; i++){
        if(markAsMultiplied[i]){
            for(int j = i * i; j <= limit; j+=i){
                markAsMultiplied[j]=false;
            }
        }
    }

    printf("Prime numbers:\n");

    for(int i = 2; i <= limit; i++){
        if(markAsMultiplied[i])
        printf("%d ", i);
    }
}

int main(){
    int limit;
    printf("Enter the limit:");
    scanf("%d",&limit);

    prime(limit);

    return 0;
}