
#include <stdio.h>
#include <stdlib.h>


//returning the local pointer from a function is possible if the local pointer is allocated memory dynamically
int* fun(){
    int *ptr = (int *)calloc(5, sizeof(int));
    return ptr;
}

int main() {

    // int *ptr_1 = (int *)malloc(5 * sizeof(int));
    
    // for(int i = 0; i < 5; i++)  scanf("%d",ptr_1 + i);

    // for(int i = 0; i < 5; i++)  printf("%d\t",*(ptr_1 + i));

    // printf("\n");

    // ptr_1 = (int *)realloc(ptr_1, 6 * sizeof(int));
    // ptr_1[5] = 6;

    // for(int i = 0; i < 6; i++)  printf("%d\t",*(ptr_1 + i));
    // free(ptr_1);
    // ptr_1 = NULL;   //for avoiding dangling pointers
    int *ptr = fun();
    for(int i = 0; i < 5; i++)  printf("%d\t",*(ptr + 1));
    free(ptr);
    ptr = NULL;


    return 0;
}