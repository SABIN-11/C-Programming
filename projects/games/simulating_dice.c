//simulation dice rolls n number of times to get the frequency of each face of dice

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM_OF_FACES 7
#define MIN 1

void random_face(int num_of_times, int *dice){

    srand(time(NULL));  //seeding the random generator to generate new random numbers every execution

    for(int i = 1; i <= num_of_times; i++)  dice[MIN + rand() % 6]++;

}

int main() {

    int *dice = (int *)calloc(NUM_OF_FACES, sizeof(int));  //dynamically allocating memory for the 6 faces in a dice
    int num_of_times = 0;   //how many times should we roll the dice

    printf("Enter how many times should the die be rolled.");
    scanf("%d", &num_of_times);

    random_face(num_of_times, dice);

    for(int i = 1; i < NUM_OF_FACES; i++){
        printf("Face %d appeared %d times.\n", i, dice[i]);
    }

    free(dice);
    dice = NULL;    //to avoid dangling pointer

    return 0;
}