#include<stdio.h>
#include<string.h>
#include<ctype.h>

//defining macro 
#define MAX_SIZE 6

void input(int, int[]);
void leftRotate(int, int[]);
void rightRotate(int, int[]);

int main(){

    int size;

    printf("Enter the size of the array:"); //asking the size from the user
    scanf("%d",&size);

    int array[size+1];

    input(size,array);

    char choice[MAX_SIZE]="0";
    char *option[2]={"left","right"};

    printf("\n\nEnter your choice(Left rotation or right rotation):");
    printf("\nEnter left for left rotation or right for right rotation:");
    // scanf("%s",choice);
    while(getchar()!='\n'); //clear input buffer

    fgets(choice,sizeof(choice),stdin);
    choice[strcspn(choice,"\n")]='\0'; //remove newline character

    if(strncmp(choice,option[0],MAX_SIZE)==0)
    leftRotate(size,array);
    

    else if(strncmp(choice,option[1],MAX_SIZE)==0)
    rightRotate(size,array);
    

    else
    printf("\nInvalid Input.Enter left or right.");

    return 0;


}

void input(int size, int array[]){

    printf("Enter the elements for the array:\n");
    for(int i=0; i<size; i++){

        printf("Element[%d]:",i);
        scanf("%d",&array[i]);

    }

    printf("\nElements before left rotating:\n");
    for(int i=0; i<size; i++)
    printf("%d\t",array[i]);

}

void leftRotate(int size, int array[]){

    int position=0;   //for the number of digits to be left rotated
    int count=0;  //to count the number of digits left rotating

    printf("\nEnter by how many position you want to left rotate:");
    scanf("%d",&position);

    count=position; //to keep the count of numbers being left rotated

    //unitl the count becomes 0
    while(count){

        array[size]=array[0];   //storing the first element in the new memory block at the end

        //i will iterate upto new block
        for(int i=0; i<size; i++)
        //left shifting the remaining elements
        array[i]=array[i+1];

        count--;

    }
    //printing the elements after left rotating  
    printf("\n\nElements after left rotating by %d position:\n",position);
    for(int i=0; i<size; i++)
    printf("%d\t",array[i]);

}

void rightRotate(int size, int array[]){

    int position=0;   //for the number of digits to be left rotated
    int count=0;  //to count the number of digits left rotating

    printf("\n\nEnter by how many position you want to right rotate:");
    scanf("%d",&position);

    count=position; //to keep the count of numbers being right rotated

    //unitl the count becomes 0
    while(count){

        for(int i=size; i>=0; i--)
        //right shifting the elements to size+1 index to empty the first block i.e 0
        array[i]=array[i-1];

        array[0]=array[size]; //assign the last element to the empty block to right rotate
        
        count--;    //decrementing the counter to show the completion of the right rotation of 1 element

    }

    printf("\n\nElements after right rotation by %d position:\n",position);
    for(int i=0; i<size; i++)
    printf("%d\t",array[i]);
    
}