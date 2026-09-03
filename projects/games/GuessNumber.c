//guess the number game

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

//function declarations
int interface();
bool rightWrong(int,int,int*);
void hint(int,int);
void HINT_A(int,int);
void HINT_B(int,int);
bool continuePlay();

const int max=100;   //defining constant
#define max_Size 4  //defining macro

int main(){

    const char *str[]={"first","second","third"};   //string array of pointers
    // int guess=-1;
    int random; //for random numeber
    int guess=-1;  //for the guess from the player

    do{ //for continuation if wanted

    int choice=interface();
    if(choice==1){

        // printf("%d",rand());
        printf("\nYou will get 3 attempts to guess the number(0-100).");

        srand(time(NULL));  //to change the random number in every execution
        random=rand() % max+1;  //to generate random number between 0 to max

        for(int i=1;i<=3;i++){  //for 3 attempts

            if(rightWrong(random,i,&guess)){    

            printf("\nYou got it right at %s attempt.\n",str[i-1]);
            break;

            }
            else{

            printf("\nYou did'nt got it right at %s attempt.\n",str[i-1]);

            //for the last iteration
            if(i==3){

                printf("\nNumber you were trying to guess was %d.\n",random);
                break;

            }

            hint(random,guess); //calling for the hint

            }


        }
    }
    else if(choice==-1) 
    break;

    else
    printf("\nInvalid number.Input 1 or 0.\n");

    } while(continuePlay());

    printf("\nThank you for playing."); //ending

    return 0;
    
}

int interface(){

    int choose;

    printf("Guess the number!\n");
    printf("Press 1 to play or 0 to exit.");
    scanf("%d",&choose);
    
    if(choose==1)    return 1;

    else if(choose==0)  return -1;

    else    return -2; 
}

//to check whether we guessed it right or not
bool rightWrong(int random,int i,int *guess_ptr){

    
    printf("\nWhat's your guess?");
    scanf("%d",guess_ptr);

    return (*guess_ptr == random);
}

//to generate hint interface
void hint(int random,int guess){

    int option;

    do{
    printf("\nYou have two options for hint(HINT A & HINT B).");
    printf("\nPress 1 for HINT A or 0 for HINT B.");
    scanf("%d",&option);

    if(option==1){

    HINT_A(random,guess);
    break;

    }

    else if(option==0){

    HINT_B(random,guess);
    break;

    }
    
    else
    printf("Choose correct option(1 or 0).\n");

    }  while(option!=1 && option!=0);

}

//first hint
void HINT_A(int random,int guess){

    if(random>guess)
    printf("\nNumber you are trying to guess is larger than %d",guess);
    else
    printf("\nNumber you are trying to guess is smaller than %d",guess);

}

//second hint
void HINT_B(int random,int guess){

    if(random%2==0)
    printf("\nNumber you are trying to guess is even");
    else
    printf("\nNumber you are trying to guess is odd");

}

//asking user if they want to restart the game again
bool continuePlay(){

    int optionAgain;
    printf("\nDo you want to restart the game again?");
    printf("\nPress 0 to restart or any other integer to exit the game.");
    scanf("%d",&optionAgain);

    return (optionAgain==0);
}