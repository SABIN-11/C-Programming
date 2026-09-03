/*Create a rock paper scissors game. There are two players
    1. User
    2. Computer

 Condition for winning
 1. Paper - Rock : Paper wins
 2. Rock - Scissors: Rock wins
 3. Paper - Scissors: Scissors wins
 
 Take the user name as input. There should be 3 rounds and track the score and display the winner name and score at the end*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 100

typedef struct var{

    char userName[MAX_SIZE];
    char *rockPaperScissor[3][6];
    char *rockPaperScissorInverted[3][6];
    int userPlay;
    int computerPlay;
    int userScore[3];
    int computerScore[3];
    char header1[MAX_SIZE];
    char header2[MAX_SIZE];
    int i;

}rps;



void input(rps*);
void result(rps*);
void scoreTable(rps*);


int main(){

    rps game={.userScore={0},.computerScore={0}};

    //original diagrams
    game.rockPaperScissor[0][0] = "    _______ ";
    game.rockPaperScissor[0][1] = "  (_____)   ";
    game.rockPaperScissor[0][2] = "  (_____)   ";
    game.rockPaperScissor[0][3] = "---'   ____) ";
    game.rockPaperScissor[0][4] = "  (____)    ";
    game.rockPaperScissor[0][5] = "---.__(___) ";

    game.rockPaperScissor[1][0] = "     _______    ";
    game.rockPaperScissor[1][1] = "---'    ____)____";
    game.rockPaperScissor[1][2] = "          ______)";
    game.rockPaperScissor[1][3] = "         _______)";
    game.rockPaperScissor[1][4] = "        _______) ";
    game.rockPaperScissor[1][5] = "---.__________) ";

    game.rockPaperScissor[2][0] = "    _______       ";
    game.rockPaperScissor[2][1] = "---'   ____)____  ";
    game.rockPaperScissor[2][2] = "          ______) ";
    game.rockPaperScissor[2][3] = "       __________)";
    game.rockPaperScissor[2][4] = "      (____)      ";
    game.rockPaperScissor[2][5] = "---.__(___)       ";

    // Inverted diagrams
    game.rockPaperScissorInverted[0][0] = "       _______ ";
    game.rockPaperScissorInverted[0][1] = "   (_____)     ";
    game.rockPaperScissorInverted[0][2] = "   (_____)     ";
    game.rockPaperScissorInverted[0][3] = " (____    '--- ";
    game.rockPaperScissorInverted[0][4] = "    (____)     ";
    game.rockPaperScissorInverted[0][5] = " (___)__.---   ";

    game.rockPaperScissorInverted[1][0] = "    _______     ";
    game.rockPaperScissorInverted[1][1] = "____(____    '---";
    game.rockPaperScissorInverted[1][2] = "(______          ";
    game.rockPaperScissorInverted[1][3] = "(_______         ";
    game.rockPaperScissorInverted[1][4] = " (_______        ";
    game.rockPaperScissorInverted[1][5] = "  (__________.'---";

    game.rockPaperScissorInverted[2][0] = "       _______    ";
    game.rockPaperScissorInverted[2][1] = "  ____(___    '---";
    game.rockPaperScissorInverted[2][2] = "(______)          ";
    game.rockPaperScissorInverted[2][3] = "(__________       ";
    game.rockPaperScissorInverted[2][4] = "      (____)      ";
    game.rockPaperScissorInverted[2][5] = "       (___)__.---";

    //taking the name of the user
    printf("Enter your name:");
    fgets(game.userName,MAX_SIZE,stdin);
    game.userName[strcspn(game.userName,"\n")]='\0';  //null terminating the name

    int length=strlen(game.userName);
   
    strncpy(game.header1,game.userName,length);
    strcpy(game.header2,"Computer");

for(game.i=0; game.i<3; game.i++){

    input(&game);
    result(&game);
    scoreTable(&game);

}

int sum1=0,sum2=0;
for(int i=0; i<3; i++){

    sum1+=game.userScore[i];
    sum2+=game.computerScore[i];

}

if(sum1>sum2)
printf("\n%s is the winner.",game.userName);

else if(sum2>sum1)
printf("\nComputer is the winner.");

else
printf("\nIt is tie.");


    return 0;
}

void input(rps *game){

    srand(time(NULL));  //time returns seconds elapsed and srand will have different seef every run

    game->computerPlay=rand() % 3 ;   //random number from 0-2

    printf("\nEnter your move. Press '0' for rock, '1' for paper or '2' for scissors:");
    scanf("%d",&game->userPlay);

}

void result(rps *game){

    if(game->userPlay==0 && game->computerPlay==2 || game->userPlay==1 && game->computerPlay==0 || game->userPlay==2 && game->computerPlay==1){

        game->userScore[game->i]=1;

    }

    else if(game->userPlay==2 && game->computerPlay==0 || game->userPlay==0 && game->computerPlay==1 || game->userPlay==1 && game->computerPlay==2){

        game->computerScore[game->i]=1;

    }

    else{

    game->userScore[game->i] = 0;
    game->computerScore[game->i] = 0;
    }

}

void scoreTable(rps *game){

    for(int j=0; j<6; j++)
        printf("%s\t%s\n",game->rockPaperScissor[game->userPlay][j],game->rockPaperScissorInverted[game->computerPlay][j]);


    if(game->i==0){
        printf("\n+----------------------+----------------------+");
        printf("\n| %-20s | %-20s |",game->header1,game->header2);
        printf("\n+----------------------+----------------------+");
        printf("\n| %-20d | %-20d |",game->userScore[game->i],game->computerScore[game->i]);
        
    }

    else if(game->i==1){

        printf("\n+----------------------+----------------------+");
        printf("\n| %-20s | %-20s |",game->header1,game->header2);
        printf("\n+----------------------+----------------------+");
        printf("\n| %-20d | %-20d |",game->userScore[game->i-1],game->computerScore[game->i-1]);
        printf("\n| %-20d | %-20d |",game->userScore[game->i],game->computerScore[game->i]);
    }
       
    else{

        printf("\n+----------------------+----------------------+");
        printf("\n| %-20s | %-20s |",game->header1,game->header2);
        printf("\n+----------------------+----------------------+");
        printf("\n| %-20d | %-20d |",game->userScore[game->i-2],game->computerScore[game->i-2]);
        printf("\n| %-20d | %-20d |",game->userScore[game->i-1],game->computerScore[game->i-1]);
        printf("\n| %-20d | %-20d |",game->userScore[game->i],game->computerScore[game->i]);
    }

}