/*finding the difference between largest and smallest integer that can be made by a number of 8 digits(0-9)*/

#include<stdio.h>

int fillArray(int number, int digits[10], int index){

    if(number == 0)
    return index;

        int remainder=number % 10;
        digits[index]=remainder;
        return fillArray(number/10, digits, index+1);

}

//sorting the digits in descending order and making the largest integer
int descending(int digits[10], int size){

    for(int i = 0; i < size; i++){

        for(int j = i + 1; j < size; j++){

            if(digits[i] < digits[j]){

                //interchanging the digits to make it in descending order
                int temp=digits[i];
                digits[i]=digits[j];
                digits[j]=temp;
            }
        }
    }

    int largest=0;
    
    for(int i = 0; i < size; i++)
    largest= largest * 10 + digits[i];    //finding the largest integer from the digits

    return largest;

}

//sorting the digits in ascending order
int ascending(int digits[10], int size){

    for(int i = 0; i < size; i++){

        for(int j = i + 1; j < size; j++){

            if(digits[i] > digits[j]){
                
                //interchanging the digits to sort in ascending
                int temp=digits[i];
                digits[i]=digits[j];
                digits[j]=temp;
            }
        }
    }

    int smallest=0;
    
    for(int i = 0; i < size; i++)
    smallest= smallest * 10 + digits[i];   //finding the smallest integer from the digits

    return smallest;

}

int main(){

    int number;
    int digits[10]={0};

    printf("Enter the number of 8 digits:");
    scanf("%d",&number);

    int size=fillArray(number,digits,0);
    int largest=descending(digits,size);
    int smallest=ascending(digits,size);

    printf("Difference:%d",largest - smallest);

    return 0;
}

