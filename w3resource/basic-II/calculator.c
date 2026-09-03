
#include<stdio.h>

void calculation(){

    char expression[20]={0};

    printf("Enter the expression:");
    scanf("%s",expression);

    float result=expression[0] - '0';

    for(int i = 0; i < 20; i++){

        if(expression[i] == 'x')
        result = result * ((float)expression[i+1] - '0');

        else if(expression[i] == '/')
        result = result / ((float)expression[i+1] - '0');

        else if(expression[i] == '+')
        result = result + ((float)expression[i+1] - '0');

        else if(expression[i] == '-')
        result = result - ((float)expression[i+1] - '0');

        else if(expression[i] == '0')
        break;

    }

    printf("%.2f",result);


}

int main(){

    calculation();

    return 0;
}