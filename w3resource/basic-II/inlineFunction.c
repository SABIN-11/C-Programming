
#include <stdio.h>

static inline int even_odd(int number){
    return (number % 2 == 0)? 1:0;
}

int main(){

    int min = even_odd(111);
    if(min) printf("Even");
    else printf("Odd");

    return 0;
}