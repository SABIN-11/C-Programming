/*converting time_t object to textual format*/

// #define __STDC_WANT_LIB_EXT1__ 1 // Enable safer C library functions
#include<stdio.h>
#include<time.h>

int main(){

    time_t now=time(NULL);  //current time in seconds since epoch
    char *now_str=ctime(&now); //convert time_t to textual format

    struct tm *month = gmtime(&now);
    printf("%s",now_str);
    printf("\n%s",asctime(month));

    return 0;

}