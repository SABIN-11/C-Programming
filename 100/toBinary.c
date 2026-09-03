//decimal to binary

// #include<stdio.h>

// #define max 10
// int decimaltoBinary(int,int[]);

// int main(){

//     int decimal=170;
//     int array[max]={0};

//     int size=decimaltoBinary(decimal,array);
//     printf("Binary value of %d:",decimal);

//     for(int i=size-1;i>=0;i--)  
//     printf("%d",array[i]);

//     return 0;

// }

// int decimaltoBinary(int decimal,int array[]){

//     int size=0;

//     for(int i=0;decimal!=0;i++){

//         array[i]=decimal%2;
//         size++;
//         decimal/=2;

//     }
//     return size;

// }

//decimal to binary using struct

#include<stdio.h>

#define max_size 10 //macro defining

//structure defining
struct binary{

    int array[max_size];
    int decimal;
    int size_1;
    int temp;
};

void binaryToDecimal(struct binary*);   //function declaration

int main(){

    struct binary conversion={{0},170,0,0};   //initializing values to the properties of struct
    conversion.temp=conversion.decimal; //assigning decimal value to temp

    binaryToDecimal(&conversion);   //function call

    printf("Binary value of %d:",conversion.temp);

    //printing the array in reverse order
    for(int i=conversion.size_1-1;i>=0;i--)  
    printf("%d",conversion.array[i]);

    return 0;

}

//function definition
void binaryToDecimal(struct binary *convert){

    for(int i=0;convert->decimal!=0;i++){

        convert->array[i]=convert->decimal%2;
        convert->size_1++;  //size counter 

        convert->decimal/=2;
    }
}