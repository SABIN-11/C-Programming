/*take a string and two integers and reverse the characters in the range[n1,n2]*/

#include<stdio.h>
#include<string.h>

#define MAX_LENGTH 50

void reverseInBetween(char string[MAX_LENGTH], int lower, int upper, int length){

    char string2[length+1]; //creating another string to take the converted sting
    int i;

    for(i = 0; i < length; i++){

        if(i == lower - 1){ //when the lower range is encountered

            //reverse the characters in between the range
            for(int k = upper - 1; k >= lower - 1; k--){

                string2[i++]=string[k];
            }

            i--;

        }

        else
        string2[i]=string[i];
    }

    string2[i]='\0';    //null terminating at the end
    
    printf("String after reversal:%s",string2);
    
}

int main(){

    char string[MAX_LENGTH];
    printf("Enter the string:");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string,"\n")]='\0'; //null terminating the string at the end

    int lowerRange,upperRange;
    printf("Enter the lower and upper range:");
    scanf("%d%d",&lowerRange,&upperRange);

    int length=strlen(string);

    if(upperRange > length || lowerRange <= 0){
        printf("ERROR! Range is not valid");
        return 1;
    }

    reverseInBetween(string, lowerRange, upperRange, length);



    return 0;
}
