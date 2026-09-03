/*find the date and time 24 months before*/
#include<stdio.h>
#include<time.h>

int main(){

    time_t today=time(NULL); //current time

    printf("Current date and time:%s",ctime(&today));
    struct tm *date=localtime(&today); //converting to local time

    date->tm_year=date->tm_year - 2;

    time_t difference=(time_t)difftime(today,mktime(date));
    char str[255];
    strftime(str,sizeof(str),"%a %b %d %H:%M:%S %Y",date);
    printf("Date and time 24 months before:%s",str);

    return 0;

}