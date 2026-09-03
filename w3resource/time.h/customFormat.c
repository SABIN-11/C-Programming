/*convert the struct tm objects into custom readble data*/
#include<stdio.h>
#include<time.h>

int main(){


    time_t now=time(NULL); //current time in seconds
    
    // struct tm *date=localtime(&now);    //converting into local format
    // char str[100];

    // strftime(str, sizeof(str), "%b %d %I:%M %p", date); //use to style the format 
    // printf("%s",str);

    // struct tm myStyle={
    //     .tm_year=124,//year 2024 since 1900
    //     .tm_mon=0, //january
    //     .tm_mday=15,
    //     .tm_hour=12,
    //     .tm_min=00,
    //     .tm_sec=00
    // };

    // char string[255];
    // strftime(string, sizeof(string), "%Y %b %d %H:%M:%S %p", &myStyle);
    // fputs(string,stdout);   //standard output
    // return 0;

    printf("%s",ctime(&now));
    struct tm *time=gmtime(&now);
    char greenwichtime[255];

    strftime(greenwichtime,sizeof(greenwichtime), "%Y %B %d %H:%M:%S %p",time);
    printf("%s",greenwichtime);
}