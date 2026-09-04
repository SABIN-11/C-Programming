//create an ascii table from 32 to 255

#include<stdio.h>

int main(){


    printf("    %-10s   %-10s   %-10s","Ch","Dec","Hex");
    printf("\n");

    printf("------------------------------------------\n");

    for(char i = 32; i <= 90; i++){

        printf("    %-10c   %-10d   %#x\n",i,i,i);

    }

    return 0;
}