//use of ftell and fseek

#include <stdio.h>

int main() {

    FILE *fptr = NULL;
    fptr = fopen64("notes.pdf", "r");
    char buffer[200];

    //read 2 lines from the file
    fgets(buffer, sizeof(buffer), fptr);
    fgets(buffer, sizeof(buffer), fptr);

    //long ftell(FILE *)
    int bytes_parsed = ftell(fptr); //ftell returns how many bytes our FILE pointer has parsed
    //it returns the number of bytes our pointer has read
    
    printf("%d", bytes_parsed);

    //int fseek(FILE *, int offset, int origin)
    //using fseek, we can change the position of our pointer
    //it returns 0 on success and -1 on failure
    int success_or_failure = fseek(fptr, -10, 1); 

    bytes_parsed = ftell(fptr);

    printf("\n%d", bytes_parsed);
    printf("\n%d", success_or_failure); //0 if success : -1 if failure

    return 0;
}