//bubble sorting

#include<stdio.h>

#define n 10
void bubbleSorting(int[]);

int main(){

    int array[n]={10,9,8,7,6,5,4,3,2,1};

    bubbleSorting(array);

    printf("After bubble sorting:\n");
    for(int i=0;i<n;i++){

    printf("%d\t",array[i]);
    
    }
    
    return 0;
}
            
void bubbleSorting(int array[]){

    int temp;

    for(int i=0;i<n-1;i++){

        // int bubble=0;
        int swapped=0;
        for(int j=0;j<n-i-1;j++){

        // if(array[bubble]>array[bubble+1]){

        //     temp=array[bubble];
        //     array[bubble]=array[bubble+1];  
        //     array[bubble+1]=temp;
        //     bubble+=1;

        // }
        // else
        // bubble+=1;
            if(array[j]>array[j+1]){

                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
                swapped=1;

            }
        }
        
        if(!swapped)
        break;

    }
}

