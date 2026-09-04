//How do you insert an element at a specific position in an array?

#include<stdio.h>
#include<stdlib.h>

//defining macro
#define MAX_SIZE 6

void askTheUser(int*,int*,int,int[]);
void insertingElement(int,int,int,int[]);

int main(){

    int array[MAX_SIZE]={1,2,4,5,6}; 
    int size=(sizeof(array)/sizeof(array[0]))-1;   
    int position,numberForInsert;
    //we want to insert 3 at 4's position
    //index of 4 is 3
    //i.e position for insert=3

    //calling function to ask the user
    askTheUser(&position,&numberForInsert,size,array);

    //calling function to insert the element
    insertingElement(position,numberForInsert,size,array);

    return 0;

}       

void askTheUser(int *ptrForPosition,int *ptrForNumber,int size,int array[]){

    //printing the array to make it more user friendly
    printf("Given below is the array\n");
    for(int i=0; i<size; i++){

        printf("%d\t",array[i]);
    }

    //asking for the position
    printf("\nEnter the position where you want to insert the number:");
    scanf("%d",ptrForPosition);

     // Validate position
    if (*ptrForPosition < 1 || *ptrForPosition > size + 1) {

        printf("Invalid position! Please enter a position between 1 and %d.\n", size + 1);
        exit(1); // Exit if position is invalid

    }

    //asking the number for insertment
    printf("\nEnter the number you want to insert in postion %d:",*ptrForPosition);
    scanf("%d",ptrForNumber);

}

void insertingElement(int position,int number,int size,int array[]){

    // Check if array has space for new element
    if (size >= MAX_SIZE) {

        printf("Cannot insert element. Array is already at maximum capacity.\n");
        exit(1); // Exit if array is full

    }
    //right shifting the elements to empty the position
    for(int i=size; i>position-1; i--){

        array[i]=array[i-1];                         

    }
    //increment of size because one element is inserted
    size++;
    array[position-1]=number;//inserting the element in the blank space

    //printing the elements after inserting
    printf("Printing the elements after insert\n");
    for(int i=0; i<size; i++)
    printf("%d\t",array[i]);
      
}