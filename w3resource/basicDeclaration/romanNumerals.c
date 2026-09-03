//printing the roman numerals from 1-100

#include<stdio.h>

int main(){

    printf("Decimal Number\t\tRoman Numeral\n");

    for(int i = 1; i <= 100; i++){

        printf("%14d\t\t",i);

        int temp=i;

            
            if(temp == 100){

                printf("C");
                temp=0;

            }

            if(temp >= 50){
            
                printf("L");
                temp-=50;

            }

            while(temp >= 10){

                printf("X");
                temp-=10;   

            }

            if(temp >= 5){

                if(temp % 10 == 9){

                    printf("IX");
                    temp-=9;
                
                }
                
                else{

                    printf("V");
                    temp-=5;
                
                }

            }

            while(temp > 0){

                if(temp % 10 == 4){

                    printf("IV");
                    temp-=4;
                
                }
                
                else{

                    printf("I");
                    temp-=1;
                
                }
            }

            printf("\n");

    }

    return 0;
}