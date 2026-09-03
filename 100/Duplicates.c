//printing duplicates from an array

#include<stdio.h>
#include<stdbool.h>

#define n 9
void duplicate(int[],int);
void print(int[],int);

int main(){

    int array1[n]={1,2,4,1,2,8,3,8,3};
    int size=sizeof(array1)/sizeof(array1[0]);  //calculating the number of elements

    duplicate(array1,size); //calling function

    return 0;

}

void duplicate(int array1[],int size){

    int array2[n],k=0;
    bool is_Notunique[n];  
    int flag=0; //to count the size of the new array
    
    for(int i=0;i<size;i++)
    is_Notunique[i]=true;  //initializing true to every element

    for(int i=0;i<size;i++){

        if(is_Notunique[i]){
            for(int j=0;j<size;j++){

                if(i!=j){   //beside itself comparing with every other elements

                    //if equal changing true into false
                    if(array1[i]==array1[j]){

                        is_Notunique[i]=false; 
                        is_Notunique[j]=false;

                    
                    }
                }
            }
            // storing one false element
            if(!(is_Notunique[i])){

            array2[k]=array1[i];
            k++;
            flag++;

            }
        }
    }
    print(array2,flag); //calling function

}

void print(int array2[],int flag){

    printf("Printing duplicate elements:\n");
    for(int i=0;i<flag;i++){

        printf("%d\t",array2[i]);

    }
}