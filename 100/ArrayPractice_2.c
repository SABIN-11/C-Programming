//How do you remove duplicates from an array?

#include<stdio.h>  
#include<stdbool.h> 

void inputElements(int,int[],bool[]);
void deleteDuplicates(int,int[],bool[]);

int main(){
    
    int size;
    //taking the size from the user
    printf("Enter the size of the array:");
    scanf("%d",&size);

    int array[size];
    bool isUnique[size];    //to keep track of duplicate elements

    inputElements(size,array,isUnique);    //for input
    deleteDuplicates(size,array,isUnique); //for removing duplicates
    
    return 0;

}

void inputElements(int size,int array[],bool isUnique[]){
    
    //taking elements as an input 
    printf("Enter the elements:\n");
    for(int i=0; i<size; i++){

        printf("Element[%d]:",i);
        scanf("%d",&array[i]);
        isUnique[i]=true;  //assigning true to every elements

    }

    //printing the elements before removing duplicates
    printf("Elements before removing\n");
    for(int i=0; i<size; i++)
    printf("%d\t",array[i]);
    
}

void deleteDuplicates(int size,int array[],bool isUnique[]){

    for(int i=0; i<size; i++){  //checking elements below itself  

        if(isUnique[i]){   //check only if frequecy is true

            for(int j=i+1; j<size; j++){
                
                if(array[i]==array[j]){ 

                    isUnique[i]=false; //assign false to isUnique if elements are matched
                    isUnique[j]=false;

                }

            }
        }
    }   

    //printing the elements after removing duplicates from the array
    printf("\n\nElements after removing duplicates\n");

    for(int i=0; i<size; i++){

        if(isUnique[i])    //printing only true elements i.e unique elements
        printf("%d\t",array[i]);

    }
}

