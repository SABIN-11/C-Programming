/*printing current local and greenwich date and time*/
#include<stdio.h>
#include<time.h>


int main(){

    clock_t start, end; //to get the time that took for the execution of the program
    start=clock();
    //get the current time in seconds since epoch: Jan 1, 1970 midnight
    time_t now = time(NULL);

    //use ctime function to change it into readable format
    char* date = ctime(&now);
    printf("Current date and time:%s",date);

    //use the structure tm in time.h library
    //use localtime function to get the local time of our region and use struct to change
    struct tm *time=localtime(&now);
    //use struct objects to get the specific data
    printf("Current hour:%d",time->tm_hour);
    printf("\nCurrent seconds:%d",time->tm_sec);
    //finding the greenwich mean time
    struct tm *gm_time=gmtime(&now);
    printf("\nCurrent hour:%d",gm_time->tm_hour);

    printf("\nCurrent local time and date:%s",asctime(time));

    end=clock();

    double seconds=(double)(end - start)/CLOCKS_PER_SEC;
    printf("Time: %lf",seconds);
    return 0;

}