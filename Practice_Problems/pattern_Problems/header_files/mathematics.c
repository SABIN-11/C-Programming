//definition for the functions of mathematics.h

#include "mathematics.h"

int factorial(int number){
    if(number == 0 || number == 1)  return 1;

    int product = 1;
    for(int i = 2; i <= number; i++)
    product *= i;

    return product;

}