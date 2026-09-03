//caluculating the angle between the hour hand and minute hand

#include<stdio.h>

int main(){

    int hour,minute;

    printf("Enter the hour and minute.(HR MIN):");
    scanf("%d%d",&hour,&minute);

    float angle=(hour * 30 + minute * 0.5) - (minute * 6); /*as 1 hour is 30 degree and 1 min is 0.5 degree in hour hand
    but in minute hand 1 min = 6 degree*/

    if(angle < 180.0)
    printf("Angle between hour and minute hand is %.2f.",angle);

    else
    printf("Angle between hour and minute hand is %.2f",360-angle);

    return 0;
}