//break into smallest possible values

#include<stdio.h>

int main(){

    int amount;

    printf("Enter the amount:");
    scanf("%d",&amount);

    printf("\n%d Note(s) of 100.", amount / 100);
    int remainder=amount % 100;
    printf("\n%d Note(s) of 50.", remainder / 50);
    remainder=remainder % 50;
    printf("\n%d Note(s) of 20.", remainder / 20);
    remainder=remainder % 20;
    printf("\n%d Note(s) of 10.", remainder / 10);
    remainder=remainder % 10;
    printf("\n%d Note(s) of 5.", remainder / 5);
    remainder=remainder % 5;
    printf("\n%d Note(s) of 2.", remainder / 2);
    remainder=remainder % 2;
    printf("\n%d Note(s) of 1.", remainder / 1);

    return 0;
}