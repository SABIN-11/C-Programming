/*creating a to-do-list for daily goals*/

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_TASKS 10
#define TASKS_LENGTH 100
#define WEEK_DAY 7

//creating a structure for better readability
typedef struct dailyTasks{

    int noOfTasks;
    char *day[WEEK_DAY];
    char taskDescription[MAX_TASKS][TASKS_LENGTH];
    int taskNumber;
    char choice;
    int lastIndex;

}task;

void inputTasks(task *list){

    for(int i = 0; i < list->noOfTasks; i++){

        printf("Enter the task %d:",i+1);
        fgets(list->taskDescription[i], TASKS_LENGTH, stdin);
        list->taskDescription[i][strcspn(list->taskDescription[i],"\n")]='\0';  //null terminating at the end of the task

    }

}

//writing the tasks in the file
void inputInFile(task *list){

    FILE *fptr=NULL;
    fptr=fopen("My notes.txt","w");

    if(fptr == NULL){
        perror("Error while opening or creating the file.");
        exit(1);    //exit out from the program directly
    }

    for(int i = 0; i < list->noOfTasks; i++){
        fprintf(fptr, "%d. ", i+1);
        fputs(list->taskDescription[i], fptr);

        fputc('\n',fptr);
    }
    

    fclose(fptr);

}

//for removing a task after it is done
void removeTasks(task *list){

    while(getchar() != '\n'); //clearing input buffer

    int k = 0; 

    FILE *fptr=NULL;

    fptr=fopen("My notes.txt","r");

    if(fptr == NULL){
        perror("Error while opening the file.");
        exit(1);    //exit out from the program directly
    }

    for(int i = 0; i < list->noOfTasks; i++){
        
        fseek(fptr, 3, SEEK_CUR); //move the pointer 3 characters ahead
        fgets(list->taskDescription[i], TASKS_LENGTH, fptr);    //reading the task and storing it in the taskDescription
        list->taskDescription[i][strcspn(list->taskDescription[i], "\n")]='\0'; //null terminating at the end of the task

    }

    fclose(fptr);

    printf("Enter the task number you want to remove.");
    scanf("%d",&list->taskNumber);

    while(getchar() != '\n'); //clearing input buffer

    FILE *fptr2=NULL;

    fptr2=fopen("My notes.txt","w");
    if(fptr2 == NULL){
        perror("Error while opening or creating the file.");
        exit(1);    //exit out from the program directly
    }

    for(int i = 0; i < list->noOfTasks; i++){

        if(i == list->taskNumber - 1){
            continue;
        }

        k++;
        fprintf(fptr2, "%d. ", k);
        fputs(list->taskDescription[i], fptr2);

        fputc('\n',fptr2);
    }

    fclose(fptr2);

    //decrementing the number of tasks as 1 task is removed
    list->noOfTasks--;
 
}

//adding a new task
void append(task *list){

    while(getchar() != '\n');
    FILE *fptr=NULL;

    fptr=fopen("My notes.txt","a");

    if(fptr == NULL){
        perror("Error while opening or creating the file.");
        exit(1);    //exit out from the program directly
    }

    for(int i = 0; i < list->noOfTasks; i++){

        printf("Enter the task %d:",i+1);
        fgets(list->taskDescription[i], TASKS_LENGTH, stdin);
        list->taskDescription[i][strcspn(list->taskDescription[i],"\n")]='\0';  //null terminating at the end of the task

    }

    for(int i = 0; i < list->noOfTasks; i++){
        fprintf(fptr, "%d. ", ++list->lastIndex);
        fputs(list->taskDescription[i], fptr);

        fputc('\n',fptr);
    }
    
    fclose(fptr);
    
}

//to get today's day
int weekDay(){

    time_t currentTime=time(NULL);//getting the current time in seconds
    struct tm *convert=localtime(&currentTime);//converting the seconds into local time
    int dayIndex=convert->tm_wday; //getting the day of the week from the structure

    return dayIndex;

}
int main(){

    task list={0,{"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"}};

    //giving user the choice to either write or remove
    printf("Do you want to input, remove or append the tasks? Press 'I' or 'i' for input, 'R' or 'r' for removing or 'A' or 'a' for appending:");
    scanf("%c",&list.choice);

    if(tolower(list.choice) == 'i'){

        int dayIndex=weekDay();
    
        printf("Enter the number of tasks for %s.",list.day[dayIndex]);
        scanf("%d",&list.noOfTasks);

        while(getchar() != '\n'); //clearing the input buffer

        inputTasks(&list);  //to get input from the user
        inputInFile(&list); //to make a file and write the task there

    }

    else if(tolower(list.choice) == 'r'){

        printf("Enter the number of current tasks: ");
        scanf("%d", &list.noOfTasks);
        removeTasks(&list); //to remove the tasks after its completion

    }

    else if(tolower(list.choice) == 'a'){
        printf("Enter the number of tasks to be append:");
        scanf("%d",&list.noOfTasks);
        printf("Enter the number of current tasks: ");
        scanf("%d", &list.lastIndex);
        append(&list);
    }

    else
    printf("Invalid Input. Press either 'i' or 'r'.");

    return 0;
}