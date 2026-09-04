//take n lines and print 3 numbers in a line starting from 1

#include<stdio.h>

int main(){

    int lines;
    int k=1;
    printf("Input the number of lines:");
    scanf("%d",&lines);

    for(int i = 1; i <= lines; i++){
        
        for (int j = 1; j <= 3; j++)
        printf("%d\t",k++);

        printf("\n");
        
    }
    return 0;
}