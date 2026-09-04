/*finding the least occuring integers in a group of n integers*/

#include<stdio.h>
#include<stdbool.h>

int main(){

    int range;

    printf("Enter the number of integers:");
    scanf("%d",&range);

    int array[range];
    int frequency[range];   //to keep track of the frequencies of each element
    int is_unique[range+1]; //to keep track of the duplicates

    for(int i = 0; i < range; i++){

        scanf("%d",&array[i]);
        frequency[i]=1; //every element in the array has frequency 1 initially
        is_unique[i]=true;  //every element is unique initially
    }

    //finding the duplicates and the frquencies
    for(int i = 0; i < range; i++){

        if(is_unique[i]){
            for(int j = i + 1; j < range; j++){

                if(array[i] == array[j]){
                frequency[i]++;
                is_unique[j]=false;
                }
            }
        }
    }

    int least=frequency[0]; //for the least frequency
    int leastOccuringIndex=0;   //to track the index for printing
    int smallest=array[0];  //if frequency is same then finding smallest element    

    for(int i = 1; i < range; i++){

        if(is_unique[i]){
            if(least > frequency[i]){   //finding the smallest frequency

                least=frequency[i];
                leastOccuringIndex=i;
            }

            else if(least == frequency[i]){ //finding the smallest element

                if(smallest > array[i]){

                    leastOccuringIndex=i;
                }
            }
        }

    }

    printf("Least occuring integer:%d",array[leastOccuringIndex]);

    return 0;
}