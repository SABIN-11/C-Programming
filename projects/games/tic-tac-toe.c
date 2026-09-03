//tictactoe game

// #include<stdio.h>
// #include<stdbool.h>

// //macro defining
// #define row 3              
// #define column 3
// #define player_X 'X'
// #define player_O 'O'
// #define max_value 15

// //function declaration
// void initialisingSpace(char ticTacToe[row][column]);
// void boxforGame(char ticTacToe[row][column]);
// void chooseMove(char ticTacToe[row][column]);
// bool winner(int decide[max_value]);

// //main function
// int main(){

//     char ticTacToe[row][column];

//     //function calling
//     initialisingSpace(ticTacToe);
//     boxforGame(ticTacToe);
//     chooseMove(ticTacToe);
//     return 0;

// }

// //assigning space
// void initialisingSpace(char ticTacToe[row][column]){

//     for(int i=0; i<row; i++){

//         for(int j=0; j<column; j++){

//             ticTacToe[i][j]=' ';
            
//         }

//     }
// }


// //choosing our play
// void chooseMove(char ticTacToe[row][column]){

//     int rowCoordinates,columnCoordinates;
//     int gameDecider_X[row];
//     int gameDecider_O[row];
//     int indexForX=0;
//     int indexForO=0;
//     int counterForX=0;
//     int counterForO=0;
//     int loss=0;

//     //9 moves as 3 x 3 
//     for(int i=1; i<=9; i++){

//         //X first play
//         if(i%2!=0){ 

//             //asking coordinates
//             printf("Choose your coordinates player X(row & column).Eg (0,0),(0,1) etc:");
//             scanf("%d %d",&rowCoordinates,&columnCoordinates);

//             //assigning X in the entered coordinates
//             ticTacToe[rowCoordinates][columnCoordinates]=player_X;
//             boxforGame(ticTacToe);  //calling to show the graph

//             gameDecider_X[indexForX++]=rowCoordinates;  //storing 3 X values
//             counterForX++;  //to assign 3 values in the array

//         //after storing 3 values
//         if(counterForX==3){
//             //if true
//             if(winner(gameDecider_X)){

//                 printf("\nPlayer_X won the game.");
//                 break;

//             }
//             //if false
//             else
//             loss++;

//         }
//     }   
//         //O second play
//         else{
            
//             printf("Choose your coordinates player O(row & column).Eg (0,0),(0,1) etc:");
//             scanf("%d %d",&rowCoordinates,&columnCoordinates);  

//             //assigning O in the entered coordinates
//             ticTacToe[rowCoordinates][columnCoordinates]=player_O;
//             boxforGame(ticTacToe);  //calling to show graph

//             gameDecider_O[indexForO++]=rowCoordinates;  //storing 3 row values
//             counterForO++;  //to assign 3 values in the array

//             //after 3 values are assigned
//             if(counterForO==3){

//                 //if true
//                 if(winner(gameDecider_O)){

//                     printf("\nPlayer_O won the game.");
//                     break;

//                 }
//                 //if false
//                 else
//                 loss++;

//                 }

//         } 

//     }
//         //if neither wins
//         if(loss==2)
//         printf("\nIt is tie.");

// }

// //to show the graph for playing
// void boxforGame(char ticTacToe[row][column]){

//     printf(" %c | %c | %c \n",ticTacToe[0][0],ticTacToe[0][1],ticTacToe[0][2]);
//     printf("---|---|---\n");
//     printf(" %c | %c | %c \n",ticTacToe[1][0],ticTacToe[1][1],ticTacToe[1][2]);
//     printf("---|---|---\n");
//     printf(" %c | %c | %c \n",ticTacToe[2][0],ticTacToe[2][1],ticTacToe[2][2]);
//     printf("\n");

// }

// //conditions to win
// bool winner(int decide[max_value]){

    
//     // int condition_2_Counter=0;  //counter for second condition

//     //first condition 
//     for(int i=0; i<row; i++){

//         int condition_1_Counter=0;  //counter for first condition

//         for(int j=0; j<column; j++){

//             if(decide[j]==i)
//             condition_1_Counter++;  

//         }
//         if(condition_1_Counter==3)   return true;
           
//     } 

//     //second condition
//     // for(int i=0; i<row; i++){

//     //     // if(decide[i]==i)
//     //     // condition_2_Counter++;
//     //     for(int j=0; j<column; j++){

//     //         if(decide[i]==j){

//     //             condition_2_Counter++;
//     //             break;

//     //         }
//     //     }

//     // }


//     // if(condition_2_Counter==3)  return true;

//     if (decide[0] == 0 && decide[1] == 1 && decide[2] == 2) return true;
//     if (decide[0] == 1 && decide[1] == 0 && decide[2] == 2) return true;
//     if (decide[0] == 0 && decide[1] == 2 && decide[2] == 1) return true;
//     if (decide[0] == 2 && decide[1] == 0 && decide[2] == 1) return true;
//     if (decide[0] == 2 && decide[1] == 1 && decide[2] == 0) return true;
//     if (decide[0] == 1 && decide[1] == 2 && decide[2] == 0) return true;

//     return false;
// }

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

//macro definition
#define SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY ' '

//function declaration
void initializingSpace(char ticTacToe[SIZE][SIZE]);
void gameBox(char ticTacToe[SIZE][SIZE]);
void choosePlay(char ticTacToe[SIZE][SIZE]);
bool winner(char ticTacToe[SIZE][SIZE],char);

//main function
int main(){

    char ticTacToe[SIZE][SIZE];

    //function calling
    initializingSpace(ticTacToe);
    gameBox(ticTacToe);
    choosePlay(ticTacToe);

    return 0;
}

//initializing space
void initializingSpace(char ticTacToe[SIZE][SIZE]){

    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++)
            ticTacToe[i][j]= EMPTY;

}

//printing the box for playing
void gameBox(char ticTacToe[SIZE][SIZE]){

    printf(" %c | %c | %c \n",ticTacToe[0][0],ticTacToe[0][1],ticTacToe[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",ticTacToe[1][0],ticTacToe[1][1],ticTacToe[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",ticTacToe[2][0],ticTacToe[2][1],ticTacToe[2][2]);
    printf("\n");

}


void choosePlay(char ticTacToe[SIZE][SIZE]){

    char current_player=PLAYER_X;   //making X the first player
    int row,column;

    for(int i=0; i<9; i++){

        printf("Player %c, enter your play(row column). Eg:(0 1):",current_player);
        scanf("%d %d",&row,&column);
    
        if(row>=0 && row<SIZE && column>=0 && column<SIZE && ticTacToe[row][column]==EMPTY){

        ticTacToe[row][column]=current_player;
        gameBox(ticTacToe);

        }

        if(winner(ticTacToe,current_player)){

            printf("Player %c is the winner.",current_player);
            return;

        }

        current_player=(current_player==PLAYER_X)?PLAYER_O:PLAYER_X;
    }
    printf("It is tie");
    exit(1);
}

bool winner(char ticTacToe[SIZE][SIZE],char player){

    for(int i=0; i<SIZE; i++){

        if(ticTacToe[i][0]==player && ticTacToe[i][1]==player && ticTacToe[i][2]==player) return true;
        if(ticTacToe[0][i]==player && ticTacToe[1][i]==player && ticTacToe[2][i]==player) return true;
    }

    for(int i=0; i<SIZE; i++){

        if(ticTacToe[0][0]==player && ticTacToe[1][1]==player && ticTacToe[2][2]==player) return true;
        if(ticTacToe[0][2]==player && ticTacToe[1][1]==player && ticTacToe[2][0]==player) return true;

    }
    return false;

}   
