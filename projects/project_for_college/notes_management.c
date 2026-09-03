//creating a notes management program with following features
//1)append, remove, search, view all notes, view all tags, exit
//2)categorization in work, personal and study
//3)prioritization in high and low
//4)due dates

#include <stdio.h>  
#include <stdlib.h> 
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <windows.h>
#include <limits.h> //for MAX_PATH used in GetFullPathName

//macros for the limits of different variables
#define MAX_TAG_LENGTH 50
#define MAX_CONTAINER_LENGTH 5000
#define MAX_NOTES 50000
#define KEY 3
#define MAX_DATE 100
#define ZERO 0
#define MAX_FOR_TOKEN 5
#define MAX_TAG_COUNT 20
#define SPACE ' '
#define E 2.718281828  //double by default until explicitly made float with suffix 'f'
#define PI 3.141592653589793238462643383279502884197169399  //double by default

//macros for the text colors
#define BLACK "\033[30m"    //Defines a black text color code
#define RED "\033[31m"    // Define red text color code
#define PURPLE "\033[35m"   //Define purple text color code
#define CYAN "\033[36m"    //Define cyan text color code
#define YELLOW "\033[33m"   // Define yellow text color code
#define BLUE "\033[34m"    // Define blue text color code

//macros for the background colors just add +10 to the same color of the text
#define BG_BLACK "\033[40m"    //Defines a black background color code
#define BG_RED "\033[41m"    // Define red background color code
#define BG_GREEN "\033[42m"   // Define green 976background color code
#define BG_PURPLE "\033[45m"   //Define purple background color code

//macro for the formatting throughout the code
//green text color
#define GREEN "\033[32m"

//macros for the formatting of the text-style
#define BOLD "\033[1m"  //Defines a bold text
#define ITALIC "\033[3m"    //Defines a italic text
#define RESET "\033[0m"   // Define reset code (back to normal black formatting)

//macros for the cursor and clear screen
//\033c clears the screen and H determines the position of the cursor, by default row 1 coloumn 1
#define CLEAR_TOP "\033c\033[1;1H\033[32m"  //Clear the screen and move the cursor to the top left (row 1 and column 1)

//structure for our notes management system
//using typedef to give it a abbreviation
typedef struct note_management_system{
    char *notes;    //for storing the notes content
    char category;  //for the choosing of category (work, study, personal)
    char *tag;  //for the tag of the note
    char important; //for the priority (HIGH/LOW)
    char *date; //for the storing of the date when reading from the file
    float year; //for the year in the deadline
    float month;    //for the month in the deadline
    float day;  //for the day in the deadline
    char **tag_container;    //for the tags of the notes
    char *plain;    //for the string Deadline: 
}NMS;   //abbreviation of note_management_system

int count_border = 0;   //this is for counting how many borders (------- ....) we have parsed
int tag_count = 0;  //for the index of the tags / length of the tags in the 2D array of pointers
char option = '\0'; //ASCII value 0 
bool flag_for_decryption = true;

//function to clear the input buffer
void clear_buffer(){

    char c; //it can be int also
    while((c = getchar()) != '\n' && c != EOF);    //getchar() checks the input buffer until it encounters a newline character
    //or until it reaches the end of input buffer
    //functions like scanf, sscanf ignores newlines and white spaces

}

void check_allocation(void *ptr) {
    if(ptr == NULL){
        perror(RED "Memory allocation failed.\n" GREEN);
        exit(EXIT_FAILURE); // Exit if allocation fails
    }
}

//function for edge case if user's input doesn't match with Y or N
void edge_case_for_yes_no(char *option){
            
    if(toupper(*option) != 'Y' && toupper(*option) != 'N'){ //if not yes or no

        while(toupper(*option) != 'Y' && toupper(*option) != 'N'){  //until its yes or no

            *option = '\0'; //remove the previous value
            printf(RED "Invalid input.");
            printf(PURPLE "\nPlease enter 'Y' for Yes or 'N' for No: ");
            scanf("%c", option);    //no & needer bcz it is call by reference 
            printf("\n");
            clear_buffer();

        }

    }
    
}

//function to encrypt the plain text
void encrypt_string(char *plain_text){

    char *str = malloc(27 * sizeof(char));
    strcpy(str, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    int length = strlen(plain_text);    //length of the string to be encrpyted

    for(int i = 0; i < length; i++){    //from 0 to length - 1

        if(isalpha(plain_text[i])){ //if the characters are alphabets
            plain_text[i] = str[((toupper(plain_text[i]) - 'A') + KEY) % 26];   //encrypt the characters
        }

    }

    free(str);
    str = NULL;

}

//function to encypt the number i.e deadline
float encrypt_numbers(int num){

    if(num == 0){
        return num;
    }
    else{
        return (num * pow(E, PI - log(2))); //return the encypted form of the number
    }

}

//function to decrypt the encrpyted string
void decrypt(NMS *manage){

    char *str = malloc(27 * sizeof(char));
    strcpy(str, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    int length = strlen(manage->notes); //length of the note to be decrpyted

    for(int i = 0; i < length; i++){    //from 0 to length - 1

        if(isalpha(manage->notes[i])){  //if it is alphabet
                
            if((toupper(manage->notes[i]) - 'A') >= 3){ //if the code of the alphabet is greater than or equals to 3
                manage->notes[i] = str[((toupper(manage->notes[i]) - 'A') - KEY) % 26]; 
            }
            else{   //otherwise find remainder of the negative value
                manage->notes[i] = str[((toupper(manage->notes[i]) - 'A') - KEY) + 26];
            }

        }   
        else if(isdigit(manage->notes[i])){ //if it is digit

            if(flag_for_decryption){   //only for deadline

                int count = 0;  // for the '-'
                char *plain_text = malloc(MAX_FOR_TOKEN * sizeof(char));    // for the string i.e year, month, day
                char *token = strtok(manage->date, "-"); // get the year, month and day

                while(token != NULL){   //while whole string is not tokenized

                    count++;    //increase the count of '-'
                    int k = 0;  // for the index of the decrypted string
                    double temp = strtod(token, NULL);  // convert the string to double format
                    int num = round((temp / pow(E, PI - log(2))));   // decrypt and find the number
                    sprintf(plain_text, "%d", num); // convert into a string again

                    while(plain_text[k] != '\0'){  
                        manage->notes[i++] = plain_text[k++];
                    }

                    if(count < 3)   manage->notes[i++] = '-';    // after year, month and day

                    token = strtok(NULL, "-");  // again tokenize from where we left off

                }

                flag_for_decryption = false;  // to only decrypt the digits in the deadline
                manage->notes[i++] = '\n';
                manage->notes[i] = '\0'; // Null-terminate the string

                free(plain_text);
                plain_text = NULL;

            }

        }

    }

    free(str);
    str = NULL;

}

//function to get the necessary inputs
void notes_for_me(NMS *manage){

    manage->year = manage->month = manage->day = 0;    //assign 0 to avoid garbage value
    manage->category = manage->important = '\0';    //assigning null terminator(ASCII : 0)

    //asking for the tag(identification) for the note
    printf("Enter the tag for your note. Tag should not include any numerical values like (0-9): ");
    fgets(manage->tag, MAX_TAG_LENGTH, stdin);
    manage->tag[strcspn(manage->tag, "\n")] = '\0'; //null terminating the string

    printf(CLEAR_TOP);

    //converting the tag to uppercase using toupper function for the comparing later on
    for(int i = 0; manage->tag[i] != '\0'; i++){

        if(isdigit(manage->tag[i])){    //if we find a digit in the tag
            printf(RED "Error: Tag should not include any numerical values like (0-9).\n" GREEN);
            exit(EXIT_FAILURE);
        }
        else{   //else simply convert it into uppercase
            manage->tag[i] = toupper(manage->tag[i]); 
        }

    }
    
    //asking the user for the category of the note
    printf("Please select a category:\n");
    printf("WORK = 'w/W'\n");
    printf("STUDY = 's/S'\n");
    printf("PERSONAL = 'p/P'\n");
    printf("Enter the character corresponding to your choice: ");
    scanf("%c", &manage->category);
    clear_buffer();

    printf(CLEAR_TOP);

    //edge case if user gives different input other than w,p or s.
    if(toupper(manage->category) != 'W' && toupper(manage->category) != 'S' && toupper(manage->category) != 'P'){  //if user doesn't enter valid input

        while(toupper(manage->category) != 'W' && toupper(manage->category) != 'S' && toupper(manage->category) != 'P'){  //until user enters a valid input

            manage->category = '\0'; //again remove the previos value
            printf(RED);   //red color to the text for error
            printf("***Invalid Category! ***\n");
            printf("Enter:\n");
            printf("  'w'/'W' for Work\n");
            printf("  'p'/'P' for Personal\n");
            printf("  's'/'S' for Study\n");
            printf(BLUE "Your choice: ");   //blue color to the text for again asking the choice
            scanf("%c", &manage->category);
            printf("\n");
            clear_buffer();

        }

    }

    printf(CYAN); 

    char *temp = malloc(MAX_NOTES * sizeof(char));  //allocating memory for temp
    check_allocation(temp);
    int total_length = 0, current_length = 0;   //for the length of the stored content of the note

    manage->notes[0] = '\0'; //to avoid concatenating junk

    //giving some information on what user is about to do and how to end the session of writing in different systems
    printf("You are now writing a note under the [%s] tag.\n", manage->tag);
    printf("When you're done, press CTRL + Z (Windows) or CTRL + D (Linux) to finish your input.\n");
    printf("---------------------------------------------------------------------------------------\n" RESET);    //for better readability

    while(fgets(temp, MAX_NOTES, stdin) != NULL){   //until user press CTRL + Z

        current_length = strlen(temp);  //get the length of the read line

        if(total_length + current_length > MAX_NOTES){  //if that line's length and the total length till now is more than MAX

            printf(RED);  //red color for the error
            printf("\n=============================================\n");
            printf("          MEMORY OVERFLOW ERROR             \n");
            printf("=============================================\n");
            printf("You exceeded the maximum allowed entries.\n");
            printf("Maximum allowed characters: %d\n", MAX_NOTES);
            printf("=============================================\n\n");
            printf(GREEN);
            exit(EXIT_FAILURE);

        }
        
        strncat(manage->notes, temp, MAX_NOTES);  //add the content in temp to notes 
        //temp will have different input everytime so we need to concatenate

        total_length += current_length; //add the length of the current line to the total length of the content
    }

    printf(CLEAR_TOP);

    char choose = '\0'; //initialize with null terminator

    if(toupper(manage->category) == 'W' || toupper(manage->category) == 'P'){

        //asking user if they want to set the deadline
        printf("Add a deadline to your task? (Y/N): ");
        scanf("%c", &choose);
        clear_buffer();

        printf(CLEAR_TOP);
        edge_case_for_yes_no(&choose);
        printf(CLEAR_TOP);

        if(toupper(choose) == 'Y'){ //if yes

            char *startupPath = malloc(MAX_PATH * sizeof(char));    //allocate memory for storing the startup folder path
            check_allocation(startupPath);
            char *username = getenv("USERNAME");
            sprintf(startupPath, "C:\\Users\\%s\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\run_due_date.bat", username);
            //get the USERNAME from the environment variable and give the full path
            
            FILE *fptr = NULL;
            fptr = fopen(startupPath, "r"); //open the run_due_date.bat

            if(fptr == NULL){   //if file does not exist

                //if deadline is set, just copy the due_dates batch file in startup folder
                char *filePath =  malloc(MAX_PATH * sizeof(char)); 
                check_allocation(filePath);

                char *filename = "run_due_date.bat";

                //get the absolute url using GetFullPathName
                //DWORD is the typedef of unsigned(+ve) long
                DWORD value_returned = GetFullPathName(filename, MAX_PATH, filePath, NULL);
                //it takes 4 arguments
                //1: the relative file path name
                //2: the maximum size that can be stored
                //3: the string to store the absolute file path
                //4: the pointer to (char *) for storing the relative file name only from absolute file name
                //it returns the size of absolute file path in success
                //it returns the size of buffer needed to store file path if the file path has lower storage
                //it returns 0 on failure

                if(!value_returned){    //if 0
                    perror(CLEAR_TOP RED "Error getting the path of due_date.exe\n" GREEN);
                    exit(EXIT_FAILURE);
                }            

                int is_error = CopyFile(filePath, startupPath, FALSE);
                //copies the file from current_file_path to destination_file_path
                //TRUE: doesn't overwrite if the same name file exists and returns error
                //good if the file doesn't already exist
                //FALSE: overwrites the already existing file
                //good for updating the file or changing something
                //CopyFile returns non-zero if successful and 0 is failure
                
                if(!is_error){
                    printf("Failed to copy the file. Error code: %lu\n", GetLastError());
                    //GetLastError returns the last error value by Windows API functions
                    //it shows 5 if the permission is denied
                    //it shows 3 if file path is invalid
                    //it shows 80 if flag is set to TRUE and file already exists
                }

            }

            //asking the user to set the deadline in year-month-day format
            printf("Enter the task deadline (YYYY-MM-DD):\n");

            printf("\nYear: "); //year
            scanf("%f", &manage->year);  //there is '\n' but it doesn't affect this scanf
            //bcz it takes %f i.e float and input buffer only affects %c i.e character
            clear_buffer();

            printf("Month(1-12): "); //month
            scanf("%f",&manage->month);
            clear_buffer();
            
            //edge case for month (if month is invalid)
            if(manage->month > 12 || manage->month < 1){  //if month is over 12 or under 1

                while(manage->month > 12 || manage->month < 1){   
                    
                    printf(RED "\nInvalid month!\n");
                    printf(YELLOW "Enter a valid month (1-12): ");
                    scanf("%f",&manage->month);
                    clear_buffer();
                    
                }
                printf("\n");
                printf(GREEN);
            }

            printf("Day(1-32): ");   //day
            scanf("%f",&manage->day);
            clear_buffer();

            //edge case for day (if day is invalid)
            if(manage->day > 32 || manage->day < 1){
                
                while(manage->day > 32 || manage->day < 1){
                    
                    printf(RED "Invalid day!\n");
                    printf(YELLOW "Enter a valid day (1-32): ");   
                    scanf("%f",&manage->day);
                    clear_buffer();

                }

                printf("\n");

            }
                
        }
        printf(CLEAR_TOP);

    }

    //asking the priority of this note
    printf("Is this note important? (Y:N): ");
    scanf("%c", &manage->important); 
    clear_buffer();

    printf(CLEAR_TOP);
    edge_case_for_yes_no(&manage->important);
    printf(CLEAR_TOP);

    free(temp); //free the allocated memory
    temp = NULL;    //to avoid dangling pointer

}

//function to append in the file
void write_in_file(NMS *manage){

    FILE *fptr = NULL;  //fptr is a pointer that points to FILE structure, but initially it is a null pointer
    fptr = fopen("notes.txt", "a"); //append because we want to add in not override the file
    //data of notes.txt will be stored in different members of the structures FILE
    //fopen will return the address to the FILE structure

    if(fptr == NULL){
        perror(RED "Error opening file.\n" GREEN);
        exit(EXIT_FAILURE);
    }

    char *categ = (char *)malloc(strlen("Personal") + 1 * sizeof(char));    //allocating memory for categ label
    check_allocation(categ);
    char *prior = (char *)malloc(strlen("High") + 1 * sizeof(char));    //allocating memory for prior label
    check_allocation(prior);

    //to write the category and priority in the file
    if(toupper(manage->category) == 'W') strcpy(categ, "Work");
    else if(toupper(manage->category) == 'P')    strcpy(categ, "Personal");
    else strcpy(categ, "Study");

    if(toupper(manage->important) == 'Y')    strcpy(prior, "High");
    else strcpy(prior, "Low");

    //strings for the labels
    char *category = malloc(strlen("Category") + 1 * sizeof(char));  //category
    check_allocation(category);
    char *priority = malloc(strlen("Priority") + 1 * sizeof(char));  //priority
    check_allocation(priority);
    char *nts = malloc(strlen("Notes") + 1 * sizeof(char));   //notes
    check_allocation(nts);

    //labels
    strcpy(category, "Category");
    strcpy(priority, "Priority");
    strcpy(nts, "Notes");

    //now encrypt the tags, categories, priorities, deadline, notes and labels
    encrypt_string(manage->tag);
    encrypt_string(categ);
    encrypt_string(prior);
    encrypt_string(manage->notes);
    encrypt_string(category);
    encrypt_string(priority);
    encrypt_string(nts);

    //now encrypt the value in deadline
    manage->year = encrypt_numbers(manage->year);
    manage->month = encrypt_numbers(manage->month);
    manage->day = encrypt_numbers(manage->day);

    //writing in the file
    fprintf(fptr, "---------------------------------------------------------------------------------------");
    fprintf(fptr, "\n[%s]", manage->tag);
    fprintf(fptr, "\n%s: %s", category, categ);
    fprintf(fptr, "\n%s: %s", priority, prior);

    if(manage->year == 0){   //if there's no deadline, make everything 0
        fprintf(fptr, "\n%s: %d-%d-%d", manage->plain, ZERO, ZERO, ZERO);
    }
    else{   //otherwise
        fprintf(fptr, "\n%s: %f-%f-%f", manage->plain, manage->year, manage->month, manage->day);   //simply print the encrypted values
    }

    fprintf(fptr, "\n\n%s\n%s", nts, manage->notes);
    fprintf(fptr, "\n[/%s]", manage->tag);
    fprintf(fptr, "\n---------------------------------------------------------------------------------------");
    fprintf(fptr, "\n");
    fprintf(fptr, "\n");

    fclose(fptr);   //fptr will not point to FILE structure now
    free(categ);
    free(prior);
    free(category);
    free(priority);
    free(nts);
    categ = prior = category = priority = nts = NULL;   //to avoid dangling pointer
}

void find_area_to_search_remove(NMS *manage, FILE *fptr, char *temp, int *count_start, int *count_end){

    if(fptr == NULL){
        printf(RED "Error opening file.\n" GREEN);
        exit(EXIT_FAILURE);
    }

    //converting the tag to uppercase
    for(int i = 0; manage->tag[i] != '\0'; i++){
        manage->tag[i] = toupper(manage->tag[i]);
    }

    encrypt_string(manage->tag); //encypt the tag

    //using sprintf to store the starting and closing tag inside the string starting_tag and closing_tag
    char *starting_tag = (char *)malloc(MAX_TAG_LENGTH * sizeof(char));
    check_allocation(starting_tag);
    sprintf(starting_tag, "[%s]", manage->tag);

    char *closing_tag = (char *)malloc(MAX_TAG_LENGTH * sizeof(char));
    check_allocation(closing_tag);
    sprintf(closing_tag, "[/%s]", manage->tag);

    for(int i = 1; fgets(temp, MAX_NOTES, fptr) != NULL; i++){

        //checking if tag is a substring inside the read line and if count_start is not found before
        if(strstr(temp, starting_tag) && *count_start == 0){  
            *count_start = i - 1;    
        }
        //checking if closing tag is a substring inside the read line and if count_start is found already
        if(strstr(temp, closing_tag) && *count_start != 0){
            *count_end = i + 1;
            break;
        }

        //checking if encryption of Deadline: is a substring in the read line or not
        if(strstr(temp, manage->plain)){
            strcpy(manage->date, temp + 9);  //copy the deadline in date
        }

    }

    if(*count_start == 0 || *count_end == 0){
        printf(RED "Tag not found in the notes.\n" GREEN);
        exit(EXIT_FAILURE);
    }

    free(starting_tag);
    free(closing_tag);
    closing_tag = starting_tag = NULL;

}

//function to remove a note from the file
void remove_from_file(NMS *manage){

    //count_start and count_end to determine the area to skip while reading from the file 
    int count_start = 0, count_end = 0, i; 
    char *temp = (char *)malloc(MAX_NOTES * sizeof(char));  //allocating memory for the temp to read lines from the file
    check_allocation(temp);

    //asking for the tag to remove
    printf("\nEnter the tag of the note which you want to remove: ");
    fgets(manage->tag, MAX_TAG_LENGTH, stdin);
    manage->tag[strcspn(manage->tag, "\n")] = '\0';

    FILE *f_remove = NULL;
    f_remove = fopen("notes.txt", "r");

    find_area_to_search_remove(manage, f_remove, temp, &count_start, &count_end);

    int total_length = 0; //for the upper bound to not cross our MAX_NOTES
    int current_length = 0; //for the length of the current note

    rewind(f_remove);   //rewind the file pointer to again point to the starting of the file

    //not having any data: null terminating it
    manage->notes[0] = '\0';
    temp[0] = '\0'; //to avoid junk

    //if tag is found
    for(int i = 1; fgets(temp, MAX_NOTES, f_remove) != NULL; i++){

        //skipping the lines which contain the tag and the closing tag
        //and copying the rest of the lines to the notes array
        if(i >= count_start && i <= count_end)  continue;

        //reading the lines from the file and storing them in temp
        current_length = strlen(temp);

        if(total_length + current_length > MAX_NOTES){  //if the total length exceeds our upper bound
            
            printf(RED "Error: The note is too long. Please limit your input to %d characters.\n",MAX_NOTES);
            free(temp);
            temp = NULL;  //avoid dangling pointer
            printf(GREEN);
            exit(EXIT_FAILURE);

        }

        strncat(manage->notes, temp, MAX_NOTES);    //concatenate the read line in the manage->notes

        total_length += current_length; //add current line length to the total length of the content
    }   

    fclose(f_remove);
    free(temp);
    temp = NULL;  //to avoid dangling pointer

}

//function to rewrite after removing the note
void write_after_removing(NMS *manage){
    
    FILE *f_write = NULL;
    f_write = fopen("notes.txt", "w");

    if(f_write == NULL){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fprintf(f_write, "%s",manage->notes);

    fclose(f_write);
}

//function to search a note from the file
void search_from_file(NMS *manage){ 

    //count_start and count_end to determine the area to skip while reading from the file 
    int count_start = 0, count_end = 0, i; 

    printf("\nEnter the tag of the note you want to search for: ");
    fgets(manage->tag, MAX_TAG_LENGTH, stdin);
    manage->tag[strcspn(manage->tag, "\n")] = '\0';

    FILE *f_search = NULL;
    f_search = fopen("notes.txt", "r");

    find_area_to_search_remove(manage, f_search, manage->notes, &count_start, &count_end);

    rewind(f_search);   //make the pointer points to the beginning of the file

    //do not have any data before taking data
    manage->notes[0] = '\0';
    
    //if tag is found
    for(i = 1; fgets(manage->notes, MAX_NOTES, f_search) != NULL; i++){

        if(i >= count_start && i <= count_end){ //if it is the area of the searched note

            if(strstr(manage->notes, "--------------------------")){
                flag_for_decryption = true; //this flag is for the decryption of deadline numbers only
            }

            decrypt(manage);
            printf("%s", manage->notes);
        }

    }

    fclose(f_search);

}

//function to view all notes from the file
void view_all_notes(NMS *manage){

    FILE *f_view = NULL;    //null pointer initially
    f_view = fopen("notes.txt", "r");   //fopen opens the notes.txt file and store its information in the member of FILE structure and returns the address of that structure

    if(f_view == NULL){ //if f_view is still a null pointer
        printf(RED "Error opening file.\n" GREEN);
        exit(EXIT_FAILURE);
    }

    while(fgets(manage->notes, MAX_NOTES, f_view) != NULL){

        //if deadline is found, copy the deadline numbers
        if(strstr(manage->notes, manage->plain)){
            strcpy(manage->date, manage->notes + 9);
        }
        //if a border is found just make the flag true
        if(strstr(manage->notes, "--------------------------")){
            flag_for_decryption = true; //this flag is for the decryption of deadline numbers only
        }       

        decrypt(manage);    //decrpyt it
        printf("%s", manage->notes);    //print in the console

    }

}

void get_tags(NMS *manage, int flag){   //flag for knowing which function called this get_tags function

    tag_count = 0;  //so that if this is called multiple times in one execution phase, we can start from beginning

    FILE *f_tags = NULL;    //NULL pointer initially
    f_tags = fopen("notes.txt", "r");   //fopen opens the tags.txt

    if(f_tags == NULL){ //if still NULL
        
        perror(RED "Error opening the file." GREEN);
        exit(EXIT_FAILURE);

    }

    if(flag == 1){

        while(fgets(manage->notes, MAX_NOTES, f_tags) != NULL){ //while not the end of file eof

            flag--; //for checking if there's no notes in the file

            if(strstr(manage->notes, "------------------------------------------------------------------------------")){  //if starting border is found

                flag_for_decryption = true;
                count_border++; //if border is found, increment the count of border

                if(count_border % 2 != 0){  //if count_border is odd

                    fgets(manage->notes, MAX_TAG_LENGTH, f_tags);  //read the line below that border, which is starting tag

                    decrypt(manage);

                    manage->tag_container[tag_count][0] = '\0'; //null terminate every string to avoid garbage values
                    strcpy(manage->tag_container[tag_count++], manage->notes);   //store the tag in the container of tags
                }

            }

        }

        if(flag == 1){
            printf("%s",RED);
            printf("Notes are not saved.");
            printf("%s",GREEN);
            exit(EXIT_FAILURE);
        }

    }   
    else if(flag == 2){

        while(fgets(manage->notes, MAX_NOTES, f_tags) != NULL){ //while not the end of file eof

            if(strstr(manage->notes, "------------------------------------------------------------------------------")){  //if starting border is found
            flag_for_decryption = true;

            manage->tag_container[tag_count][0] = '\0'; //null terminate every string to avoid garbage values
            strncat(manage->tag_container[tag_count], manage->notes, MAX_NOTES);

                while(1){ //while true

                    fgets(manage->notes, MAX_NOTES, f_tags);    //read from the file

                    //if Deadline string is found
                    if(strstr(manage->notes, manage->plain)){
                        strcpy(manage->date, manage->notes + 9);    //just copy the deadline number in the date string
                    }

                    if(strstr(manage->notes, "-------------------------")){  //if ending border is found
                        strncat(manage->tag_container[tag_count], manage->notes, MAX_NOTES);
                        flag_for_decryption = true;
                        break;  //break out of the loop
                    }                  

                    decrypt(manage);

                    //concatenate all the notes from the starting tag to ending tag into tag container 2D array
                    strncat(manage->tag_container[tag_count], manage->notes, MAX_NOTES);
                            
                }
                tag_count++;    //increase the tag count index for the next tag
            }

        }
        
    }

    fclose(f_tags); //close the file pointer after reading from the file

}

int compare(const void *str1, const void *str2){
    return strcmp(*(char **)str1, *(char **)str2);
}

//function to see the list of tags of notes
void list_of_tags(NMS *manage, bool remove_or_list){

    get_tags(manage, 1);   //get all the tags in tag container

    printf(CLEAR_TOP);
    printf("List of tags:\n\n");
    for(int i = 0; i < tag_count; i++){
        printf("%s", manage->tag_container[i]);
    }

    //if this function is called by remove feature, then simply return after printing the unsorted list of tags
    //we don't want to show the do you want to sort alphabetically option in this case
    if(!remove_or_list) return;

    printf("\nWould you like to sort the tags in alphabetical order? (y/n): ");
    scanf("%c", &option);
    clear_buffer();

    edge_case_for_yes_no(&option);

    if(toupper(option) == 'Y'){
        printf(CLEAR_TOP);
        qsort(manage->tag_container, tag_count, sizeof(manage->tag_container[0]), compare);
        printf("List of tags in sorted order:\n\n");
        for(int i = 0; i < tag_count; i++){
            printf("%s", manage->tag_container[i]);
        }
        printf("\n");
    }
    
}

//sorting functions below
// 1: ALPHABETICALLY SORTING
//function to find all the tags of the notes from the file
void sort_content_alphabetically(NMS *manage){

    //finding the tags and storing them in the tag_container
    get_tags(manage, 2);

    qsort(manage->tag_container, tag_count, sizeof(manage->tag_container[0]), compare);   //using qsort function to sort the tags alphabetically

    //After sorting, print the content in the sorted order
    for(int i = 0; i < tag_count; i++){
        printf("%s", manage->tag_container[i]);
    }
    
}

//2: CATEGORY SORTING
//function to sort the notes by category
void sort_content_by_category(NMS *manage, char *category){

    FILE *f_sort = NULL;  // File pointer to manage sorted notes data

    // Open "notes.txt" in read mode to access notes for sorting
    f_sort = fopen("notes.txt", "r");
    if(f_sort == NULL){
        perror(RED "Error: Unable to open 'notes.txt' for reading.\n" GREEN);  // Display error message in red if file fails to open
        exit(EXIT_FAILURE);  // Exit the program if file opening fails
    }

    int len_before_category = 0;  // Length of the previous lines read for offset calculation
    int border_flag = 0;  // Flag to determine starting and ending borders of notes
    bool pointer_rewind = false;  // Indicates if the file pointer should be rewound to read a specific note

    // Read lines from the file until the end is reached
    while(fgets(manage->notes, MAX_NOTES, f_sort) != NULL){

        // Check if the current note contains the plain text identifier
        if(strstr(manage->notes, manage->plain)){
            strcpy(manage->date, manage->notes + 9);  // Extract date from the note
        }

        // Check for the start border of the notes section
        if(strstr(manage->notes, "--------------------------------------------------------------------------------")){
            border_flag++;  // Increment the border flag when the start border is found
            len_before_category = 0;  // Reset length counter
        }

        // If the pointer_rewind is true
        if(pointer_rewind){

            if(strstr(manage->notes, "-----------------------------")){
                flag_for_decryption = true;
            }
            decrypt(manage);  // Decrypt the current note
            printf("%s", manage->notes);  // Display the decrypted note
        }

        // Calculate the length of the read line
        len_before_category += (strlen(manage->notes) + 1);
        //when fgets read a line and store it in manage->notes, the newline character '\n' is also stored
        //so when we take the length of the manage->notes, '\n' is also included
        //however in windows system, newline character is stored in 2 bytes rather than 1
        //they are stored like this \r\n instead of \n
        //but in unix-based system like linux and macos, newline is stored in 1 byte like '\n' simply
        //so for that extra '\r' in windows, we must add 1 in the length

        // If the pointer hasn't been rewound yet
        if(!pointer_rewind){
            // Check if the current note contains the specified category
            if(strstr(manage->notes, category)){
                // Rewind the file pointer by len_before_category offset of the note to read it
                fseek(f_sort, -len_before_category, SEEK_CUR);  
                pointer_rewind = true;  // Set the flag to indicate rewinding is done
                border_flag = 0;  // Reset the border flag
            }
        }

        // If two borders have been detected, reset the flags
        if(border_flag == 2){
            border_flag = 0;  // Reset the border flag
            pointer_rewind = false;  // Allow for reading the next set of notes
            // printf("\n");
        }
    }

    fclose(f_sort);  // Close the file after finishing the reading process

}


//our main function
int main() {

    //step 1: Memory allocation
    NMS *manage = malloc(sizeof(NMS));   //allocating memory for the structure NMS
    check_allocation(manage);
    manage->notes = malloc(MAX_NOTES * sizeof(char)); //allocating memory for the string inside the structure
    check_allocation(manage->notes);
    manage->tag = malloc(MAX_TAG_LENGTH * sizeof(char)); //allocating memory for tag inside the structure
    check_allocation(manage->tag);
    manage->date = malloc(MAX_DATE * sizeof(char)); //allocating memory for the date string that stores deadline
    check_allocation(manage->date);
    manage->plain = malloc((strlen("Deadline") + 1) * sizeof(char));    //allocating memory for the Deadline: substring
    check_allocation(manage->plain);

    strcpy(manage->plain, "Deadline");
    encrypt_string(manage->plain);  //encrypting it to compare it with the content in the file

    //allocating memory to store the tags of the notes
    //this stores the tags in one case and whole notes in another case
    manage->tag_container = malloc(MAX_TAG_COUNT * sizeof(char *));  //allocate memory for the 2D array of pointers
    check_allocation(manage->tag_container);

    for(int i = 0; i < MAX_TAG_COUNT; i++){
        manage->tag_container[i] = malloc(MAX_CONTAINER_LENGTH * sizeof(char));  //alloacting memory for the pointers in the 2D array
        check_allocation(manage->tag_container[i]);
    }

    //these are the foramatting for design in the terminal
    //this clears the terminal and positions the cursor at the top left row: 1 column: 1
    //and FORMAT adds green color to the text and bold that text
    printf(CLEAR_TOP);

    //step 2: Taking user input on what do they want to do
    while(1){   //while true

        //prompting the user for better user experience
        printf("=== NOTES MANAGEMENT SYSTEM ===\n");
        printf("Add a new note    - 'a/A'\n");  
        printf("Remove a note     - 'r/R'\n");  
        printf("Search a note     - 's/S'\n"); 
        printf("View all notes    - 'v/V'\n");   
        printf("List of tags      - 't/T'\n");   
        printf("\nPlease select an option. Enter the corresponding character: ");   

        scanf("%c", &option);   //scanf takes the user input from input buffer
        clear_buffer(); //clearing the input buffer for any newline character left over

        printf(CLEAR_TOP);

        if(toupper(option) == 'A'){ //if user wants to append

            while(1){   //while true

                option = '\0';  //again assign null terminator, remove the previous value
                notes_for_me(manage);  //for filling in all the information of the note
                write_in_file(manage); //for writing those information in file

                printf("Would you like to add another note? (Y for Yes, N for No): ");
                scanf("%c", &option);
                clear_buffer(); 

                printf(CLEAR_TOP);
                edge_case_for_yes_no(&option);
                printf(CLEAR_TOP);

                if(toupper(option) == 'N')  break;

            }
            break;
        }

        else if(toupper(option) == 'R'){

            while(1){   //while true

                option = '\0';  //again assign null terminator, remove the previous value
                list_of_tags(manage, false);    //show the tags to the user for better user experience
                remove_from_file(manage);   //function to removet that tag from the file
                write_after_removing(manage);  //writing in the file after removing from the file

                printf("\nNote is removed.\n");
                //asking if the user wants to remove again
                printf("\nWould you like to remove another note? (Y/N): ");
                scanf("%c", &option);
                clear_buffer();
                printf(CLEAR_TOP);

                edge_case_for_yes_no(&option);  //pass by reference

                if(toupper(option) == 'N'){
                    break;
                }  //if no, break out from the loop
            }
            break;
        }

        else if(toupper(option) == 'S'){

            while(1){
                
                option = '\0';  //assign null terminator to remove previous value
                list_of_tags(manage, false);    //show the tags to the user for better user experience
                search_from_file(manage);

                //asking the user if they want to search again
                printf("\nWould you like to search again?(Y:N): ");
                scanf("%c", &option);
                clear_buffer();

                if(toupper(option) == 'N')  break;  //if no, just break out of the loop
                else    printf(CLEAR_TOP);

                edge_case_for_yes_no(&option);
                
            }
            break;

        }

        else if(toupper(option) == 'V'){    //if user wants to view all notes

            option = '\0';  //reassign null termintor ASCII : 0 to option
            view_all_notes(manage);

            // Prompt user for sorting options
            printf("\n\nWould you like to sort the notes? (Enter the letter corresponding to your choice):\n");
            printf("Alphabetically            'a/A'\n");
            printf("By Category               'c/C'\n");
            printf("By Priority               'p/P'\n");
            printf("No Sorting                'n/N'\n");
            printf("Your choice: ");   
            scanf("%c", &option);
            clear_buffer();

            if(toupper(option) == 'A'){
                printf(CLEAR_TOP);
                printf("Alphabetically sorted notes:\n\n");
                sort_content_alphabetically(manage);
            }
            else if(toupper(option) == 'C'){
                
                printf(CLEAR_TOP);
                option = '\0';
                printf("Please choose a category to sort by:\n");
                printf("Work                      w/W\n");
                printf("Personal                  p/P\n");
                printf("Study                     s/S\n");
                printf("Your choice: ");
                scanf("%c", &option);
                clear_buffer();

                printf(CLEAR_TOP);

                if(toupper(option) == 'W'){
                    printf("Sorted notes by work:\n\n");
                    strcpy(manage->tag, "CATEGORY: WORK");//using tag to aviod creating another array
                    encrypt_string(manage->tag);
                    sort_content_by_category(manage, manage->tag);
                }
                else if(toupper(option) == 'P'){
                    printf("Sorted notes by personal:\n\n");
                    strcpy(manage->tag, "CATEGORY: PERSONAL");  //using tag to aviod creating another array
                    encrypt_string(manage->tag);
                    sort_content_by_category(manage, manage->tag);
                }
                else if(toupper(option) == 'S'){
                    printf("Sorted notes by study:\n\n");
                    strcpy(manage->tag, "CATEGORY: STUDY"); //using tag to aviod creating another array
                    encrypt_string(manage->tag);
                    sort_content_by_category(manage, manage->tag);                
                }
                else{
                    printf(RED "Invalid choice.\n" GREEN);
                }

            }
            else if(toupper(option) == 'P'){    //if user wants to sort by priority

                printf(CLEAR_TOP);
                option = '\0';  //to avoid some garbage values
                printf("Please choose a priority to sort by:\n");
                printf("High                 h/H\n");   //high priority
                printf("Low                  l/L\n");   //low priority
                printf("Your choice: ");
                scanf("%c", &option);
                clear_buffer(); 

                printf(CLEAR_TOP);
                if(toupper(option) == 'H'){
                    printf("Sorted notes by high priority:\n\n");
                    strcpy(manage->tag, "PRIORITY: HIGH");  //using tag to aviod creating another array
                    encrypt_string(manage->tag);
                    sort_content_by_category(manage, manage->tag);
                }
                else if(toupper(option) == 'L'){
                    printf("Sorted notes by low priority:\n\n");
                    strcpy(manage->tag, "PRIORITY: LOW");  //using tag to aviod creating another array
                    encrypt_string(manage->tag);
                    sort_content_by_category(manage, manage->tag);                    
                }
                else{
                    printf(RED "Invalid choice!\n" GREEN);
                }
            }
            
            break;  //bcz we view all notes only once

        }

        else if(toupper(option) == 'T'){

            option = '\0';  //reassign null termintor ASCII : 0 to option
            list_of_tags(manage, true);
            break;  //bcz we view all tags only once

        }

        else{  
            printf(RED "Invalid option! Please select a valid choice.\n\n" GREEN);
        }

    }

    free(manage->notes);
    free(manage->tag);
    free(manage->date);
    free(manage->plain);

    for(int i = 0; i < MAX_TAG_COUNT; i++){
        free(manage->tag_container[i]);
    }

    free(manage->tag_container);
    free(manage);

    //to avoid dangling pointers
    manage->notes = manage->tag = manage->date = manage->plain = NULL;
    manage = NULL;

    return 0;
}
