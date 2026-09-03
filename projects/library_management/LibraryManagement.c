//This is a book management system

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 50

//structure to store the title author and genre
typedef struct Books_Management_System{
    char *title;
    char *author;
    char *genre;
}BMS;


void clear_input_buffer(){
    while(getchar() != '\n');   //clearing the input buffer for taking string input
}

//function to read the information from existing file to remove items
int read_books_from_file(BMS manage[MAX_SIZE]){
    
    FILE *fp_to_read = NULL;
    fp_to_read = fopen("books.txt", "r");
    if(fp_to_read == NULL){
        perror("Could not open file books.txt\n");
        exit(1);
    }

    int count_books = 0; //to count the number of books
    char line[MAX_SIZE]; //to read a line from the existing file
    int i = 0;

    while(fgets(line, sizeof(line), fp_to_read) != NULL){   

        //one way of parsing through the label is to use sscanf function
        //sscanf: int sscanf(const char *str, const char *format, ...);
        //it reads from str string and interprets it according to the format
        //and stores the results in the variables passed as arguments
        //using sscanf(line, "title:%[^\n]", manage[i].title)   
        //we can parse the title and store the result in manage[i].title


        //second way to parse
        //reading only the value and ignoring the label
        // Skip if it's an empty line
        if (strlen(line) < 1) continue;

        //strstr:finds a substring within a string
        // Read and skip the border line
        if (strstr(line, "------------------------------")) {
            continue;
        }

        // Read title
        if (strstr(line, "Title:")) {
            strcpy(manage[i].title, line + 6);
            manage[i].title[strcspn(manage[i].title, "\n")] = '\0';  // Null-terminate
        }

        // Read author
        if (strstr(line, "Author:")) {
            strcpy(manage[i].author, line + 7);
            manage[i].author[strcspn(manage[i].author, "\n")] = '\0';  // Null-terminate
        }

        // Read genre
        if (strstr(line, "Genre:")) {
            strcpy(manage[i].genre, line + 6);
            manage[i].genre[strcspn(manage[i].genre, "\n")] = '\0';  // Null-terminate
            i++;
            count_books++;
        }

    }

    fclose(fp_to_read);
    return count_books;
    
}

//function to find the last book number
int last_book_number(){

    FILE *fp = fopen("books.txt", "r");

    if (fp == NULL) {
        perror("File unable to open");
        exit(EXIT_FAILURE);  // If file doesn't exist, exit failure
    }

    int last_no = 0;
    char line[MAX_SIZE];

    while (fgets(line, sizeof(line), fp) != NULL) {
        //sscanf:reads from the "line" string and look for book %d(interger) and stores it in last_no 
        if (sscanf(line, "Book %d", &last_no) == 1);

    }

    fclose(fp);

    return last_no;
}

//displaying the information of the file
void display_info(){

    FILE *fp = NULL;
    fp = fopen("books.txt", "r");
    if(fp == NULL){
        perror("File unable to open.");
        exit(EXIT_FAILURE);
    }

    char *str = (char *)malloc(sizeof(char) * MAX_SIZE);

    //read the data until the end of the file
    while(fgets(str, sizeof(str), fp) != NULL){
        printf("%s",str);
    }

    free(str);
    fclose(fp);
    
}

void append_in_file(BMS manage[MAX_SIZE], int num_of_info){

    FILE *fp_for_append = NULL;
    fp_for_append = fopen("books.txt", "a");
    if(fp_for_append == NULL){
        perror("File unable to open.");
        exit(EXIT_FAILURE);
    }   

    int last_book_no = last_book_number();

    for(int i = 0; i < num_of_info; i++){
        fprintf(fp_for_append, "Book %d\n",++last_book_no);
        fprintf(fp_for_append, "Title: %s\n", manage[i].title);
        fprintf(fp_for_append, "Author: %s\n", manage[i].author);
        fprintf(fp_for_append, "Genre: %s\n", manage[i].genre);
        
        // Print a border or delimiter
        fprintf(fp_for_append, "-----------------------------\n");
    }

    fclose(fp_for_append);
}

void save_in_file(BMS manage[MAX_SIZE], int num_of_books, int book_to_remove){

    FILE *fp = NULL;
    fp = fopen("books.txt","w");    //making a file to write the information in it
    if(fp == NULL){
        perror("Could not open file\n");
        exit(EXIT_FAILURE);
    }

    int symbol_no = 0;
    for(int i = 0; i < num_of_books; i++){

        if(i == book_to_remove - 1) continue;

        fprintf(fp, "Book %d\n", ++symbol_no);
        fprintf(fp, "Title:%s\n", manage[i].title);
        fprintf(fp, "Author:%s\n", manage[i].author);
        fprintf(fp, "Genre:%s\n", manage[i].genre);
        
        // Print a border or delimiter
        fprintf(fp, "-----------------------------\n");
    }
    fclose(fp);

}

void remove_from_file(BMS manage[MAX_SIZE], int *num_of_info){

    int book_to_remove;
    printf("Enter the book number you want to remove: ");
    scanf("%d", &book_to_remove);

    clear_input_buffer();

    int count_books = read_books_from_file(manage);
    save_in_file(manage, count_books, book_to_remove);

}

//function to take information about the books from the user
int information_of_book(BMS manage[MAX_SIZE]){

    char choice;
    int count_input = 0;

    printf("Enter the following information about the book:\n");

    for(int i = 0; i < MAX_SIZE; i++){

        printf("\nTitle:");
        fgets(manage[i].title, MAX_SIZE, stdin);
        manage[i].title[strcspn(manage[i].title,"\n")] = '\0';  //null terminating the string
        
        printf("\nAuthor:");
        fgets(manage[i].author, MAX_SIZE, stdin);
        manage[i].author[strcspn(manage[i].author,"\n")] = '\0';  //null terminating the string

        printf("\nGenre:");
        fgets(manage[i].genre, MAX_SIZE, stdin);
        manage[i].genre[strcspn(manage[i].genre,"\n")] = '\0';  //null terminating the string

        count_input++;

        //asking if the user want to add more
        printf("\nDo you want to add more books?(y/n):");
        scanf("%c",&choice);

        clear_input_buffer();

        if(tolower(choice) != 'y') break;

    }

    return count_input;
}

int main() {

    BMS manage[MAX_SIZE]; //struct variable
    int num_of_info;

    //dynamically allocating memeory for the strings
    for(int i = 0; i < MAX_SIZE; i++){
        manage[i].title = (char*)malloc(MAX_SIZE * sizeof(char));
        manage[i].author = (char*)malloc(MAX_SIZE * sizeof(char));
        manage[i].genre = (char*)malloc(MAX_SIZE * sizeof(char));
    }

    display_info();
    char choice;

    printf("\nDo you want to append or remove books?(a/r):");
    scanf("%c",&choice);

    clear_input_buffer();

    if(tolower(choice) == 'a'){
        num_of_info = information_of_book(manage);
        append_in_file(manage, num_of_info);
    }
    else if(tolower(choice) == 'r'){
        remove_from_file(manage, &num_of_info);
    }
    // int num_of_info = information_of_book(manage);
    // save_in_file(manage, num_of_info, -1);

    for(int i = 0; i < MAX_SIZE; i++){
        free(manage[i].title);
        free(manage[i].author);
        free(manage[i].genre);
    }
    
    return 0;
}
