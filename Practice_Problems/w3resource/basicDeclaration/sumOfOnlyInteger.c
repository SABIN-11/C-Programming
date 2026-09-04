/*calculate the sum of only +ve integers from a sentence*/

#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX_LENGTH 80

int sumOfDigits(char sentence[MAX_LENGTH]){

    int sum[80]={0};
    int k = 0;
    int length=strlen(sentence) - 1;
    for(int i = 0; i <= length; i++){

        if(isdigit(sentence[i]) && !isdigit(sentence[i+1])){

            sum[k]=sum[k] + (sentence[i] - '0');
            k++;
        }

        else if(isdigit(sentence[i]) && isdigit(sentence[i+1]) || isdigit(sentence[i]) && isdigit(sentence[i-1])){
        
            while(isdigit(sentence[i])){

                sum[k] = sum[k] * 10 + (sentence[i] - '0');
                i++;

            }

            k++;
            i--;

        }
        
    }

    sum[k]='\0';

    int s=0;

    for(int i = 0; i < k; i++)
    s+=sum[i];

    return s;
}

int main(){

    char sentence[MAX_LENGTH];

    printf("Enter a sentence:");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence,"\n")]='\0';

    printf("Sum of numericals value:%d",sumOfDigits(sentence));

    return 0;
}
