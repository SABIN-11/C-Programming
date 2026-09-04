//printing the name and score of the entered students using struct

#include<stdio.h>
#include<string.h>

#define NAME_SIZE 50    //macro defining
//struct defining
struct student{

    char name[NAME_SIZE];
    float score;
};

int main(){

    struct student arrayStudent[5]; //array of structures

    //taking input
    for(int i=0;i<5;i++){

        printf("Enter the name of student %d:",i+1);
        fgets(arrayStudent[i].name,NAME_SIZE,stdin);
        arrayStudent[i].name[strcspn(arrayStudent[i].name,"\n")]='\0';  //replace the newline character by null teminator

        printf("Enter the GPA of %s:",arrayStudent[i].name);
        scanf("%f",&arrayStudent[i].score);

        while(getchar()!='\n'); // Clear the input buffer

        printf("\n");
    } 
    printf("Student\t\t\t\t\tGPA\n");
    //printing
    for(int i=0;i<5;i++){

        printf("\n%s\t\t\t\t\t%.2f",arrayStudent[i].name,arrayStudent[i].score);

    }

    return 0;
}