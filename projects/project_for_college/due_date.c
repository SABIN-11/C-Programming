//separate function to check if deadline is met

//preprocessor directives
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <math.h>
// #include "encryption.h"
#include <mmsystem.h>   //for PlaySound
// #pragma comment(lib, "winmm.lib") //tells the linker to link the winmm.lib multimedia library 

#define MAX_TEMP_LENGTH 500
#define MAX_TAG_LENGTH 30
#define KEY 3
#define E 2.718281828  //double by default until explicitly made float with suffix 'f'
#define PI 3.141592653589793238462643383279502884197169399  //double by default
#define MAX_MESSAGE_LENGTH 100


void encrypt_string(char *plain_text){

    char *str = malloc(27 * sizeof(char));
    strcpy(str, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    int length = strlen(plain_text);

    for(int i = 0; i < length; i++){
        if(isalpha(plain_text[i])){
            plain_text[i] = str[((toupper(plain_text[i]) - 'A') + KEY) % 26];
        }
    }

    free(str);
    str = NULL;

}

void message_box(char *message){

    //PlaySound is a function in windows API
    //It plays a sound when a message box is opened
    //it takes 3 arguments
    //1. the path to the sound to be played
    //2. the type of sound to be played
    //3. the flags for the sound to be played 
    //SND_FILENAME - the name of the wav sound file
    //SND_ASYNC - the sound is played asynchronously with the message, the sound will be played even when the message is being displayed
    //the function doesn't wait for the sound to be finished
    //use -lwinmm flag in terminal to tell the linker to link our program with the Windows Multimedia API Library
    //-l prefix indicates library
    PlaySound(TEXT("airplane.wav"), NULL, SND_FILENAME | SND_ASYNC);

    //MessageBox is a function in windows API(Application Programming Interface)
    //it takes 4 arguments 
    //NULL-to indicate the message box doesn't have parent window
    //message - the message to be displayed
    //"Title" - the title of the message box
    //MB_OK is the ok button
    //MB_ICONINFORMATION - the icon of the message box
    MessageBox(NULL, message, "Deadline for task", MB_OK | MB_ICONINFORMATION);

}

void print_from_deadline(){

    FILE *f_deadline = NULL;
    f_deadline = fopen("notes.txt", "r");    //fopen will return the address of the FILE structure

    if(f_deadline == NULL){
        printf("\nError opening file.");
        exit(EXIT_FAILURE);
    }

    char *temp = (char *)malloc(MAX_TEMP_LENGTH * sizeof(char));
    char *date = (char *)malloc(MAX_TAG_LENGTH * sizeof(char));
    char *plain = malloc(11 * sizeof(char));    //for the encrypted text of Deadline: 
    char *message_to_be_displayed = malloc(MAX_MESSAGE_LENGTH * sizeof(char));  //this is for the message to be passed to another function
    strcpy(plain, "Deadline: ");
    encrypt_string(plain);

    if(temp == NULL || date == NULL){
        printf("\nMemory allocation error.");
        exit(EXIT_FAILURE);
    }

    int year = 0, month = 0, day = 0;
    int count_border = 0;

    //for the decrtyption part
    char *str = malloc(27 * sizeof(char));
    strcpy(str, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    //read until the end of file
    while(fgets(temp, MAX_TEMP_LENGTH, f_deadline) != NULL){


        if(strstr(temp, plain)){ //if Deadline: string is found
            strcpy(date, temp + 9);   //copy the deadline in string format
        }
        else{   //if its not deadline line
            if(strstr(temp, "----------------------------")){   //check if border is found
                count_border++;

                if(count_border % 2 != 0){  //if its starting border
                    fgets(temp, MAX_TEMP_LENGTH, f_deadline);   //read the tag line below it

                    //decypt the tag
                    for(int i = 0; temp[i] != '\0'; i++){
                        if(isalpha(temp[i])){
                            if((toupper(temp[i]) - 'A') >= 3){ //if the code of the alphabet is greater than or equals to 3
                                temp[i] = str[((toupper(temp[i]) - 'A') - KEY) % 26]; 
                            }
                            else{   //otherwise find remainder of the negative value
                                temp[i] = str[((toupper(temp[i]) - 'A') - KEY) + 26];
                            }
                        }
                    }
                    sprintf(message_to_be_displayed, "Deadline is here for your %s note.", temp);
                }
            }
            continue;
        }

        //now tokenize the deadline with the delimeter -
        char *token = strtok(date, "-");  //delimeter is "-"
        //strtok returns the pointer to the first character of the substring when - is encountered
        //it automatically null terminate at that point in the original string
        int i = 1;

        while(token != NULL){   //it will return NULL after traversing through the string

            double temp = strtod(token, NULL);  //convert the string to double format

            if(i == 1){
                year = round((temp / pow(E, PI - log(2))));   //decrypt and find the year
            }
            else if(i == 2){
                month = round((temp / pow(E, PI - log(2))));   //decrypt and find the month
            }
            else{
                day = round((temp / pow(E, PI - log(2))));  //decrypt and find the day
            }
           
            token = strtok(NULL, "-");  //to start from the position where we left off

            i++;
        }

        //fill the required members of the structure with the taken values from the note in the file
        struct tm time_in_note = {0};   //initialize every members as 0
        time_in_note.tm_year = year - 1900; //bcz struct tm stores year after JAN 1, 1900
        time_in_note.tm_mon = month - 1;    //bcz struct tm stores month from 0(JAN)
        time_in_note.tm_mday = day; //starts from 1 only

        // now using time functions to get the deadline
        time_t current_time = time(NULL);   //get the current time in seconds sincce Jan 1, 1900

        //convert the manually assigned structure to elapsed seconds using mktime
        time_t seconds_elapsed = mktime(&time_in_note); //mktime returns the structure in seconds format

        if((difftime(current_time, seconds_elapsed) >= 0) && year != 0 && month != 0 && day != 0){
            message_box(message_to_be_displayed);
        }

    }

    free(temp);
    free(date);
    free(plain);
    free(message_to_be_displayed);
    temp = date = plain = message_to_be_displayed = NULL;

}

int main(){
    print_from_deadline();
    return 0;
}
