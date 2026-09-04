/*extract words of 3-6 characters long from a sentence where words are separated by delimeters*/

#include<stdio.h>
#include<string.h>

void extractWords(char *sentence, char *delimeters){

    char *token=strtok(sentence, delimeters);   //returns the pointer to the first character of the token when delimeters are encounterd
    //returns null if the sentence is finished

    while(token != NULL){

        if(strlen(token) >= 3 && strlen(token) <= 6)
        printf("%s\n",token);

        token=strtok(NULL, delimeters); //use NULL to continue tokenizing

    }

}

int main(){

    char delimeters[8]=" ,.!?\t\n";
    char sentence[1024];

    printf("Enter a sentence:");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence,"\n")]='\0';  //null terminating at the end

    extractWords(sentence, delimeters);

    return 0;
}