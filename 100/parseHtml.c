//parsing a html line
//input:    <h1>    This is a heading     </h1>
//output:   This is a heading

#include<stdio.h>
#include<string.h>
#include<ctype.h>

//defining macro 30 for the maximum size of the string
#define MAX_SIZE 50

void parse(char[MAX_SIZE]);

int main(){

    char stringHtml[MAX_SIZE]="<h1>    This is a heading    </h1>";

    parse(stringHtml);

    return 0;

}

void parse(char stringHtml[MAX_SIZE]){

    int length=strlen(stringHtml);  //33
    
    int i=0;

    // Find the start of the content within the tags
    while(i<length && stringHtml[i]!='>'){
    i++;
    }
    // Move past '>'
    i++;

    // Skip initial whitespace
    while(i<length && isspace(stringHtml[i])){
    i++;
    }
    
    // Print the content until the closing tag
    while(stringHtml[i]!='<'){

        if(!isspace(stringHtml[i]) ||  !isspace(stringHtml[i+1]))
        putchar(stringHtml[i]);

        i++;

    }


}