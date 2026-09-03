//information about the return value in the main function

#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *fptr = NULL;
    fptr = fopen("main.txt", "r");

    if(fptr == NULL){
        perror("Error while opening the file");
        fclose(fptr);
        exit(EXIT_FAILURE); //program exit with 1 i.e error
    }
    
    fclose(fptr);
    return 0;
}