/*creating a classic hangman game to guess a word*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include<stdbool.h>

#define space ' '
#define dash '_'

typedef struct hangman{

    char figure[7][30];   //array for the figure of the hangman
    char fruits[10][15];    //array for the fruits section
    char animals[10][15];   //array for the animals section
    char vegetables[10][15];    //array for the vegetable section
    char technology[10][30];    //array for the animals section
    char anime[10][20]; //array for the anime section
    int randomIndex;
    int choice;
    char userGuess;
    int wordOrLetter;
    char guessTheWord[30];

}hang;

void printDash(size_t length, bool duplicate[length], char *randomWord);
void clearInputBuffer(void);
void printHangman(int k, hang *genres);


//function to ask the user for their interest genre
void getUserInput(hang *genres){
    printf("\nWelcome to Hangman Game!\n\n");
    printf("Presented below are our genres:\n");
    printf("1. Fruits\n");
    printf("2. Animals\n");
    printf("3. Vegetables\n");
    printf("4. Technology\n");
    printf("5. Anime\n");
    printf("You must press the corresponding number to select a genre: ");
    scanf("%d", &genres->choice);    //get the genre user wants to play

    clearInputBuffer();
}

//function to randomly generate a index between 0 and 10 for the randoms string
void generateRandom(hang *genres){

    srand(time(NULL));  //different seed everytime
    genres->randomIndex = rand() % 10; //random idnex between 0 and 10

}

//function to get the guesses given by the user
void guessByTheUser(hang *genres){

    //rules and information of the game
    printf("\n**Game Rules:**\n\n");
    printf("* You will have 7 attempts to make the guess.\n");
    printf("* If you guess a letter correctly, it will be revealed in the word.\n");
    printf("* If you guess incorrectly, a part of the hangman figure will be drawn.\n");
    printf("* You can guess a letter by typing it in, and then pressing Enter.\n");

    char *randomWord=NULL;

    switch (genres->choice) {

        case 1: randomWord = genres->fruits[genres->randomIndex]; break;
        case 2: randomWord = genres->animals[genres->randomIndex]; break;
        case 3: randomWord = genres->vegetables[genres->randomIndex]; break;
        case 4: randomWord = genres->technology[genres->randomIndex]; break;
        case 5: randomWord = genres->anime[genres->randomIndex]; break;
        default: printf("Invalid choice!\n"); return;

    }
    
    //get the length of the random word
    size_t length=strlen(randomWord);
    //make a boolean array to check for duplicates
    bool *duplicate = (bool *)malloc(sizeof(bool) * length);

    printf("\nLet's go. Here is your word(length:%zu)\n",length);

    for(size_t i = 0; i < length; i++){
        printf("%c\t",dash);
        duplicate[i]=true;
    }

    // printf("\nPress '1' to directly guess the word or '0' for letter:");
    int k = 0; //to keep track of which part of hangman to print
    int countCorrect=0; //to count the correct letters

    for(int i = 1; k < 7; i++){

        printf("\n\nAttempt %d\n",i);
        printf("Guess a letter: ");
        scanf(" %c", &genres->userGuess);

        clearInputBuffer();
        bool correctGuess=false;    //to check whether the user had correct or incorrect guess

        //checking if letter is present in the string
        for(size_t i = 0; i < length; i++){

            if(tolower(genres->userGuess) == tolower(randomWord[i]) && duplicate[i]){
                duplicate[i]=false;
                correctGuess=true;
            }

        }

        if(correctGuess){
            printDash(length, duplicate, randomWord);
            countCorrect++; //problem here
        }
        else{
            printHangman(k, genres);
            k++;
        }
       
    }

    if(countCorrect == length)
    printf("\nYou got it right. You win.");

    else{
    printf("\nYou didn't got it right on letters.");
    printf("\nYou have last attempt to guess by word.");
    printf("\nGuess the word:");
    scanf("%s",genres->guessTheWord);

        if(strcmp(genres->guessTheWord, randomWord) == 0){
        printf("\nYou got it right in words.");
        }
        else{
        printf("\nYou lost in words also.");
        }

    }

    free(duplicate);
    
}

//function to print the dashes in the remaining spot
void printDash(size_t length, bool duplicate[length], char *randomWord){

    for(int i = 0; i < length; i++){

        if(duplicate[i])
        printf("%c\t",dash);
        // printf("-\t");

        else
        printf("%c\t",randomWord[i]);

    }
    printf("\n");

}

//function to print a part of hangman if the guess is incorrect
void printHangman(int k, hang *genres){

    switch(k){

        case 0: printf("%s\n",genres->figure[0]);
        break;

        case 1: 
        printf("%s\n",genres->figure[0]);
        printf("%s\n",genres->figure[1]);
        break;

        case 2: 
        printf("%s\n",genres->figure[0]);
        printf("%s\n",genres->figure[1]);
        printf("%s\n",genres->figure[2]);
        break;

        case 3: 
        printf("%s\n",genres->figure[0]);
        printf("%s\n",genres->figure[1]);
        printf("%s\n",genres->figure[2]);
        printf("%s\n",genres->figure[3]);
        break;

        case 4: 
        printf("%s\n",genres->figure[0]);
        printf("%s\n",genres->figure[1]);
        printf("%s\n",genres->figure[2]);
        printf("%s\n",genres->figure[3]);
        printf("%s\n",genres->figure[4]);
        break;

        case 5: 
        printf("%s\n",genres->figure[0]);
        printf("%s\n",genres->figure[1]);
        printf("%s\n",genres->figure[2]);
        printf("%s\n",genres->figure[3]);
        printf("%s\n",genres->figure[4]);
        printf("%s\n",genres->figure[5]);

        break;

        default: 
        printf("%s\n",genres->figure[0]);
        printf("%s\n",genres->figure[1]);
        printf("%s\n",genres->figure[2]);
        printf("%s\n",genres->figure[3]);
        printf("%s\n",genres->figure[4]);
        printf("%s\n",genres->figure[5]);
        printf("%s\n",genres->figure[6]);

        break;

    }

}

void clearInputBuffer(void){
    while(getchar() != '\n'); 
}


//main function
int main(void){

    //first task to store values in the arrays
    hang genres={
    .fruits={"Apple", "Banana", "Cherry", "Elderberry", "Blueberry", "Grape", "Pineapple", "Kiwi", "Mango", "Orange"},
    .animals={"Cat", "Dog", "Horse", "Cow", "Pig", "Lion", "Tiger", "Zebra", "Deer", "Vulture"},
    .vegetables={"Carrot", "Potato", "Tomato", "Cucumber", "Broccoli", "Radish", "Brinjal", "Spinach", "Cauliflower", "Bittergourd"},
    .technology={"Computer", "Smartphone", "Internet", "Software", "Hardware", "Database", "Network", "Cybersecurity", "Artificial Intelligence", "Algorithm"},
    .anime={"Naruto", "DragonBall", "OnePiece", "Bleach", "AttackonTitan", "DeathNote", "FullmetalAlchemist", "YuYuHakusho", "Haikyuu", "Dororo"},
    .figure={
        " _______  ",
        "|       | ",
        "|       O ",
        "|      /|\\",
        "|      / \\",
        "|           ",
        "|_________|"
        }
    };

   getUserInput(&genres);
//    generateRandom(&genres);
   guessByTheUser(&genres);

   return 0;
    
}
