#include<stdio.h>
//declaring functions
void qn1();
void qn2();
void qn3();
void qn4();
void qn5();
int cont();
int total=0;
int main(){
    int option;
    top:
    printf("Press 1 to play the quiz.\nPress 0 to exit.");
    scanf("%d",&option);
    while(1){
    if(option==1){
        qn1();
        printf("\n\n");
        if(cont()==0) break;

        qn2();
        printf("\n\n");
        if(cont()==0) break;

        qn3();
        printf("\n\n");
        if(cont()==0) break;

        qn4();
        printf("\n\n");
        if(cont()==0) break;

        qn5();
        printf("\n\n");
        break;
    }
    else if(option==0) break;
    else{
        printf("Invalid input!Press 0 or 1.\n");
        goto top;
    }
    }
    printf("Your total point is %d.",total);
    printf("\nThanks for playing!");
    return 0;
}
//question 1
void qn1(){
    int ans1,opt;
    printf("A.  What is the capital city of France?\n");
    printf("1.Berlin\n2.London\n3.Paris\n4.Washington");
    printf("\nEnter your answer:");
    scanf("%d",&ans1);
    if(ans1==3)
    {
    printf("You got it right.You just earned 10 points.");
    total+=10;
    }
    else
    printf("\nYou got it wrong.\nCorrect Answer:3(Paris)");
    
    
}
//question 2
void qn2(){
    int ans1;
    printf("B.  Who wrote the play Romeo and Juliet?\n");
    printf("1.Charles Dickens\n2.Mark Twain\n3.William Shakespeare\n4.Jane Austen");
    printf("\nEnter your answer:");
    scanf("%d",&ans1);
    if(ans1==3)
    {
    printf("You got it right.You just earned 10 points.");
    total+=10;
    }
    else
    printf("\nYou got it wrong.\nCorrect Answer:3(William Shakespeare)");
   
}
//question 3
void qn3(){
    int ans1,opt;
    printf("C.  What is the chemical symbol for the element gold?\n");
    printf("1.Ag\n2.Au\n3.Gd\n4.Go");
    printf("\nEnter your answer:");
    scanf("%d",&ans1);
    if(ans1==2)
    {
    printf("You got it right.You just earned 10 points.");
    total+=10;
    }
    else
    printf("\nYou got it wrong.\nCorrect Answer:2(Au)");
    
}
//question 4
void qn4(){
    int ans1,opt;
    printf("D.  Which planet is known as the Red Planet?\n");
    printf("1.Earth\n2.Jupiter\n3.Mercury\n4.Mars");
    printf("\nEnter your answer:");
    scanf("%d",&ans1);
    if(ans1==4)
    {
    printf("You got it right.You just earned 10 points.");
    total+=10;
    }
    else
    printf("\nYou got it wrong.\nCorrect Answer:4(Mars)");
    
}
//question 5
void qn5(){
    int ans1,opt;
    printf("E.  Who was the first President of the United States?\n");
    printf("1.Thomas Jefferson\n2.John Adams\n3.George Washington\n4.Abraham Lincoln");
    printf("\nEnter your answer:");
    scanf("%d",&ans1);
    if(ans1==3)
    {
    printf("You got it right.You just earned 10 points.");
    total+=10;
    }
    else
    printf("\nYou got it wrong.\nCorrect Answer:3(George Washington)");
    
}
//asking the user if they want to continue or not
int cont(){
    int c;
    printf("Do you want to continue?\nPress 1 to continue or 0 to exit.");
    scanf("%d",&c);
    printf("\n");
    return c;
}