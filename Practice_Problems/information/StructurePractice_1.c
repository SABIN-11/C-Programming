//printing the information of n employees using structure

#include<stdio.h>
#include<string.h>

#define n 50    //defining macro

//defining structure
typedef struct employee{
    char name[n];
    int age;
    char address[n];
}sabin;

int main(){

    sabin info[3];

    for(int i=0;i<3;i++){

        printf("Enter the name of employee %d:",i+1);
        // scanf("%s",info[i].name);
        fgets(info[i].name,n,stdin);
        info[i].name[strcspn(info[i].name,"\n")]='\0';

        printf("Enter the age of employee %d:",i+1);
        scanf("%d",&info[i].age);

        // Clear the input buffer after reading age
        while (getchar() != '\n');

        printf("Enter the address of employee %d:",i+1);
        // scanf("%s",info[i].address);
        fgets(info[i].address,n,stdin);
        info[i].address[strcspn(info[i].address,"\n")]='\0';

        printf("\n");

    }
    printf("\n");

    for(int i=0;i<3;i++){

       printf("Name of employee %d is %s",i+1,info[i].name);
       printf("\nAge of employee %d is %d",i+1,info[i].age);
       printf("\nAddress of employee %d is %s",i+1,info[i].address);
       printf("\n\n");
    }

    return 0;

}