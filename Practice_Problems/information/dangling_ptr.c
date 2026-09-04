
#include <stdio.h>
#include <stdlib.h>

int* fun(){
    int num = 10;
    return &num;
}

int main() {

    int *ptr = fun();   //this becomes a dangling pointer as its pointing to a non-existing memory location
    printf("%d",*ptr);
    return 0;
}