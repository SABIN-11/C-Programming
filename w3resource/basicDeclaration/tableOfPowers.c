//print 2 to the power i , i(+ve) & i(-ve), i([0,10])

#include<stdio.h>
#include<math.h>

int main(){

    printf("i               2^i               2^-i");
    printf("\n");

    for(float i = 0; i <= 10; i++){

        printf("%f",i);
        printf("%15f",pow(2,i));
        printf("%15f",pow(2,-i));

        printf("\n");
    }


    return 0;
}