// Define a struct called Address with members street (string), city (string), and zip (integer). Then define a struct called Employee with members name (string), age (integer), and address (of type Address). Write a program to create an instance of Employee, assign values to its members, and print these values

#include<stdio.h>
#include<string.h>

#define stringSize 50   //macro defining

struct Address{

    char street[stringSize];
    char city[stringSize];
    int zip;

};

struct Employee{

    char name[stringSize];
    int age;
    struct Address address;

};

void input(struct Employee *emp);
void output(struct Employee *emp);

int main(){

    struct Employee emp;

    input(&emp);
    printf("\n");
    output(&emp);

    return 0;
}

void input(struct Employee *emp){

    printf("Enter your name:");
    fgets(emp->name,stringSize,stdin);
    emp->name[strcspn(emp->name,"\n")]='\0';

    printf("Enter your age:");
    scanf("%d",&emp->age);

    while(getchar()!='\n');    // Clear the input buffer

    printf("Enter your street name:");
    fgets(emp->address.street,stringSize,stdin);
    emp->address.street[strcspn(emp->address.street,"\n")]='\0';

    printf("Enter your city name:");
    fgets(emp->address.city,stringSize,stdin);
    emp->address.city[strcspn(emp->address.city,"\n")]='\0';

    printf("Enter the zip for your city:");
    scanf("%d",&emp->address.zip);

    while(getchar()!='\n');

}

void output(struct Employee *emp){

    printf("Name:%s\n",emp->name);
    printf("Age:%d\n",emp->age);
    printf("Street:%s\n",emp->address.street);
    printf("City:%s\n",emp->address.city);
    printf("ZIP:%d\n",emp->address.zip);
}