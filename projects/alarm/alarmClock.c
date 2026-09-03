//create a alarm clock that prints a message on its set time

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main() {

    int hour, minute;
    printf("Enter the following information to set the alarm:\n");
    printf("Hour:");
    scanf("%d",&hour);
    printf("\nMinute:");
    scanf("%d",&minute);

    time_t current_time = time(NULL);
    struct tm *local = localtime(&current_time);

    struct tm alarm = *local;
    alarm.tm_hour = hour;
    alarm.tm_min = minute;
    alarm.tm_sec = 0;

    if(difftime(mktime(&alarm),current_time) < 0){
        alarm.tm_mday++;
    }

    time_t alarmTime = mktime(&alarm);

    while(1){
        
        time(&current_time);    //get the new current time

        if(difftime(alarmTime, current_time) <= 0){

            Beep(700,2000); //700hz frequency and 2 seconds time
            printf("Wake up!\n");  
            break;
        }

        Sleep(1); //waits 1000 milliseconds i.e 1 second to reduce cpu usage

    }

    return 0;
}