
#include <stdio.h>

int main() {

    int rows = 7;

    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= i; j++){
            printf("%c",'*');
        }
        printf("\n");
    }
    return 0;
}