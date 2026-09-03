
#include <stdio.h>
#include <string.h>

int main() {

    char str[10] = "Hello";

    str[0] = 'Y';

    printf("%s",str);

    char string[2][10] = {"Hello", "World"};
    printf("\n%s",string[1]);

    strcpy(string[0], "Yello");
    printf("\n%s", string[0]);

    char *arr[2] = {"Hello", "World"};
    printf("\n%s",arr[0]);

    char s[2][2][10] = {{"Hello", "World"}, {"Why", "Where"}};
    printf("\n%s",s[1][1]);

    char *st[2][2] = {{"Hi", "Whose"}, {"When", "Whom"}};
    printf("\n%s",st[0][1]);

    char (*x)[2] = {"Hello", "World"};
    printf("\n%s",x);

    return 0;
}