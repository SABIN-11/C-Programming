/*input 2 sequence and find the intersection*/

#include<stdio.h>
#include<stdbool.h>

#define MAX_ITEMS 100

void intersection(int noOFItems1, int noOFItems2, int sequence_A[MAX_ITEMS], int sequence_B[MAX_ITEMS]){

    bool duplicate[MAX_ITEMS]={false};

    for(int i = 0; i < noOFItems1; i++){

        for(int j = 0; j < noOFItems2; j++){

            if(sequence_A[i] == sequence_B[j]){

                duplicate[i]=true;
                break;
            }
        }
    }

    //create a different array to store the true values
    int storeTrue[MAX_ITEMS],count=0,temp;
    for(int i = 0; i < noOFItems1; i++){
        if(duplicate[i]){
            storeTrue[count++]=sequence_A[i];
        }
    }

    //arranging in ascending
    for(int i = 0; i < count - 1; i++){
        for(int j = i + 1; j < count; j++){
            if(storeTrue[i] > storeTrue[j]){
                temp=storeTrue[i];
                storeTrue[i]=storeTrue[j];
                storeTrue[j]=temp;
            }
        }
    }

    printf("Printing the intersection:\n");
    //printing after arranging
    for(int i = 0; i < count; i++)
    printf("%d\t",storeTrue[i]);


}

int main(){

    int noOFItems1, noOFItems2, great;
    printf("Input the number of items to be entered for sequence A(1-100):");
    scanf("%d",&noOFItems1);

    printf("Input the number of items to be entered for sequence B(1-100):");
    scanf("%d",&noOFItems2);

    if(noOFItems1 > MAX_ITEMS || noOFItems2 > MAX_ITEMS){
        printf("Error!");
        return 1;
    }

    int sequence_A[MAX_ITEMS]={0}, sequence_B[MAX_ITEMS]={0};

    printf("Enter the elements for sequence A:\n");
    for(int i = 0; i < noOFItems1; i++)
    scanf("%d",&sequence_A[i]);

    printf("Enter the elements for sequence B:\n");
    for(int i = 0; i < noOFItems2; i++)
    scanf("%d",&sequence_B[i]);

    intersection(noOFItems1, noOFItems2, sequence_A, sequence_B);


    return 0;
}