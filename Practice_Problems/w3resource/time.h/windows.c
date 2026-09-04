/*make a to-do-list and timer to remind the date*/

#include<stdio.h>
#include<time.h>
#include<windows.h> //for Sleep

int main(){

    // time_t current_time=time(NULL);

    // printf("Current time: %ld\n",current_time); //returns the current calender time

    time_t start=time(NULL);    //starting time

    Sleep(5000);    //halt the execution of the program for given milliseconds
    
    time_t end=time(NULL);  //end time

    double diff=difftime(end,start);    //returns the differnce between the first and last time

    printf("Differnce between start and end: %.2f",diff);


    return 0;
}