/*find the seconds elapsed since the beginning of the month*/
#include<stdio.h>
#include<time.h>

#define second 86400

int main(){

    time_t t = time(NULL);  // get the current time in seconds
    struct tm *tm = localtime(&t); // convert to local time

    // int m_day=tm->tm_mday;
    // int hour=tm->tm_hour;
    // int min=tm->tm_min;
    // int sec=tm->tm_sec;

    // printf("Seconds elapsed:%d",((m_day - 1) * 86400) + (hour * 60 + min) * 60 + sec);  //get the seconds elapsed since the start of the month

    //set the objects of the struct tm to the beginning of the month 
    tm->tm_hour=0;
    tm->tm_min=0;
    tm->tm_sec=0;
    tm->tm_mday=1;

    //calculate the difference of the seconds of the current seconds and the seconds elapsed since the begn of the month
    double difference=difftime(t,mktime(tm));
    printf("Seconds elapsed since the beginning of the month is %lf",difference);

    return 0;

}