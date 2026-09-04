//self referntial structures

#include <stdio.h>

struct info{
    int num;
    char alp;
    struct info *ptr;
};

int main() {

    struct info var2 = {11, 'V', NULL};
    struct info var1 = {10, 'A', &var2};

    printf("%d %c\n",var1.num, var1.alp);
    printf("%d %c",var1.ptr->num, var1.ptr->alp);

    return 0;
}