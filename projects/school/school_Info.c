//make a system that can store all the information about the students, teachers, and staffs of your school in the form of structures
//gpa of students and storing attendence

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

//defining macro
#define MAX_SIZE 20
#define FULL_MARKS 600

//defining structures
typedef struct school_Info{

    char name[MAX_SIZE][MAX_SIZE];
    int class[MAX_SIZE];
    int totalMarks[MAX_SIZE];
    float GPA;
    char teachingSubject[MAX_SIZE][MAX_SIZE];
    int salary[MAX_SIZE];
    char choice[MAX_SIZE];
    char option[2][MAX_SIZE];
    int Count;

}sja;   //sital jyoti academy

void students_Info(sja *info);
void teachers_Info(sja *info);
void printStudentInfo(sja *info);
void printTeacherInfo(sja *info);

int main(){

    sja info={{""}, {0}, {0}, 0.0, {""}, {0}, "", {"student","teacher"}, 0};
    // sja info={.option={"student","teacher","staff"}};    
    char printOption;

    do{

    printf("\nDo you want to store student or teacher information?");
    printf("\nEnter student for student info or teacher for teacher info:");

    scanf("%s",info.choice);

    while(getchar()!='\n'); //clear input buffer

    if(strcmp(info.choice,info.option[0])==0)
    students_Info(&info);   

    else if(strcmp(info.choice,info.option[1])==0)
    teachers_Info(&info);
    
    else{
        printf("Invalid input. Please enter 'student' or 'teacher'.\n");
        continue;
    }

    printf("\nDo you want to print the information on the screen? Enter 'y' to print or 'n' to exit: ");
    scanf(" %c", &printOption);

    while (getchar() != '\n'); // Clear input buffer

    if (printOption == 'y') {

        if (strcmp(info.choice, info.option[0]) == 0) 
        printStudentInfo(&info);

        else if (strcmp(info.choice, info.option[1]) == 0) 
        printTeacherInfo(&info);
            
        } 

        else if (printOption == 'n')    
        exit(0);
            
        else {

            printf("Invalid input. Exiting.\n");
            exit(1);

        }
        
    }while(1);

    return 0;
}

void students_Info(sja *info){

    char cont;
    int i=0;
    do{

    printf("\nEnter the name of the student:");
    fgets(info->name[i],MAX_SIZE,stdin);
    info->name[i][(strcspn(info->name[i],"\n"))]='\0';
    
    printf("Enter %s's class:",info->name[i]);
    scanf("%d",&info->class[i]);

    printf("Enter the full marks obtained by %s:",info->name[i]);
    scanf("%d",&info->totalMarks[i]);

    while(getchar()!='\n'); //clearing input buffer

    printf("\nPress y to continue or n to exit:");  //asking to continu or stop
    cont=getchar();
    i++;    
    
    while(getchar()!='\n'); //clearing input buffer

    }   while(tolower(cont)!='n' && i<MAX_SIZE);    //until user stops or reaching the memory limit

    info->Count=i;   //counting the number of students information stored
    
}

//printing the students info
void printStudentInfo(sja *info){

    for(int i=0; i<info->Count; i++){
        
    printf("\nName:%s",info->name[i]);
    printf("\nClass:%d",info->class[i]);
    printf("\nTotal Obtained Marks:%d",info->totalMarks[i]);

    info->GPA=(float)(info->totalMarks[i]*4)/(float)FULL_MARKS;
    printf("\nGPA:%.2f",info->GPA);

    printf("\n");
    }   

}

void teachers_Info(sja *info){

    char cont;
    int i=0;
    do{

    printf("\nEnter the name of the teacher:");
    fgets(info->name[i],MAX_SIZE,stdin);
    info->name[i][(strcspn(info->name[i],"\n"))]='\0';
    
    printf("Enter %s's subject:",info->name);
    scanf("%s",info->teachingSubject[i]);

    printf("Enter the monthly salary of %s:",info->name[i]);
    scanf("%d",&info->salary[i]);

    while(getchar()!='\n'); //clearing input buffer

    printf("\nPress y to continue or n to exit:");  //asking to continu or stop
    cont=getchar();
    i++;    
    
    while(getchar()!='\n'); //clearing input buffer

    }   while(tolower(cont)!='n' && i<MAX_SIZE);    //until user stops or reaching the memory limit

    info->Count=i;   //counting the number of students information stored
}

//printing the teachers info
void printTeacherInfo(sja *info){

    for(int i=0; i<info->Count; i++){
        
    printf("\nName:%s",info->name[i]);
    printf("\nTeaching Subject:%s",info->teachingSubject[i]);
    printf("\nMonthly Salary:Rs %d",info->salary[i]);

    printf("\n");
    }   

}