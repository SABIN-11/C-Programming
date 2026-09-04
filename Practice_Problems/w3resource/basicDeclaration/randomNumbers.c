//generate 50 random numbers between -0.5 and 0.5 and writes them to the file rand.dat

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define max 0.5f
#define min -0.5f

int main(){

    FILE *fptr=NULL;

    fptr=fopen("rand.dat","w");

    if(fptr == NULL){

        perror("Error while opening or creating the file.");
        return 1;

    }

    int range;
    printf("Input how many random numbers you need:");
    scanf("%d",&range);

    fprintf(fptr,"%d",range);

    float random;

    srand(time(NULL));

    for(int i = 1; i <= range; i++){

        random= min + (double)rand() / RAND_MAX * (max - min);
        fprintf(fptr,"\n%f",random);

    }

    fclose(fptr);

    return 0;
}