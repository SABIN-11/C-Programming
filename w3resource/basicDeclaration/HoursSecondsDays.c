//convert to hours, minutes and seconds

#include<stdio.h>

int main(){

    int numberOfSeconds;

    printf("Enter the seconds:");
    scanf("%d",&numberOfSeconds);

    int hours=numberOfSeconds / 3600;
    int minutes=(numberOfSeconds % 3600) / 60;
    int seconds=((numberOfSeconds % 3600) % 60);

    printf("H:M:S - %d:%d:%d",hours,minutes,seconds);

    return 0;
}