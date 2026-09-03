//reversing the order of words in a sentence

#include<stdio.h>
#include<string.h>

//macro defining
#define max_word 10
#define max_word_length 25
#define max_sentence_length 100

//structure defining
struct reverse{
    
    char str[max_sentence_length];
    char words[max_word][max_word_length];
    char *token;
    char *delimiters;
    int wordCount;

};

//function declaration
void reverseOrder(struct reverse*);

//main function
int main(){

    struct reverse store={.delimiters=" ,!.", .wordCount=0,.str="0"};   //initializing members of reverse struct

    printf("Enter a sentence:");
    fgets(store.str,max_sentence_length,stdin); //taking input in str
    store.str[strcspn(store.str,"\n")]='\0';    //removing the newline charater when we hit enter i.e "\n"

    reverseOrder(&store);   //calling reverseOrder and passing address of store struct

    //printing words in reverse order
    for(int i=store.wordCount-1;i>=0;i--){

        printf("%s",store.words[i]);
        
        if(i>0)
        printf(" ");

    }

    return 0;
}

//function definition
void reverseOrder(struct reverse *store){

    store->token=strtok(store->str,store->delimiters);  
    /* strtok divides the sentence in different tokens when it encounters delimiters(!,. )*/
    /* it returns the pointer to the first character*/      
    /* prototype:   char *strtok(char *str, const char *delim);*/  
    /* it returns NULL if there are no tokens*/
    /*it replaces the delimiters by '\0*/

    while(store->token!=NULL){  //until '\0'

        strcpy(store->words[store->wordCount++],store->token);
        store->token=strtok(NULL,store->delimiters);    //NULL indicates string after previous token

    }

}