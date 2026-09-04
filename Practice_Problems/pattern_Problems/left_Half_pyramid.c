
#include <stdio.h>

int main() {

    int rows = 7;
    for(int i = 0; i < rows; i++){

        for(int j = 0; j < rows - i - 1; j++){
            printf("%c",' ');
        }
        for(int k = 0; k <= i; k++){
            printf("%c",'*');
        }

        printf("\n");
    }
    return 0;
}