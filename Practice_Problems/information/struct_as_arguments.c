
#include <stdio.h>
#include <stdlib.h>

typedef struct values{
    int a;
    int b;
}var;

var* format(){
    var *p = (var *)malloc(sizeof(var));
    p->a = 10;
    p->b = 20;
    return p;
}

int main() {

    var *ptr_1 = format();
    printf("%d %d",ptr_1->a, ptr_1->b);
    free(ptr_1);
    ptr_1 = NULL;

    return 0;
}
