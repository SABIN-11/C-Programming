//learning about command line arguments in the main function

#include <stdio.h>

int main(int argc, char *argv[]){

    printf("No of arguments: %d\n", argc);

    for(int i = 0; i < argc; i++){
        printf("%s ", argv[i]);
    }
    return 0;
}