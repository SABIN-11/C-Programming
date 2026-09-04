//calculating the value of S

#include<stdio.h>

int main(){

    float sum=0;

    for(int i = 1; i <= 50; i++){
        sum += 1/(float)i;
    }
    printf("Value of S:%f",sum);

    return 0;
}