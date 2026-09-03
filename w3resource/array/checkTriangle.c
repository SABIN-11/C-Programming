/*find the number of triangles that can be formed from an array*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>

//function to count the total combinations that can be formed using nCr
int countCombn(int n, int r) {

    if (r > n || r < 0) {
        return 0;  // Invalid case
    }
    
    return (int)(tgamma(n + 1) / (tgamma(r + 1) * tgamma(n - r + 1)));
}


//function to find if triangle is formed
bool is_triangle_possible(int a, int b, int c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}


int main(void){

    int size, countTriangle = 0;
    printf("Enter the number of elements you want in the array:");
    scanf("%d",&size);

    int *array_1 = (int *)malloc(size * sizeof(int));
    if(array_1 == NULL){
        perror("Memory error\n");
        exit(1);
    }

    //input the elements
    printf("Enter the elements:\n");
    for(int i = 0; i < size; i++)   scanf("%d",array_1 + i);

    int number_Of_Combinations = countCombn(size, 3);
    //for the index of the combinations elements
    int first = 0, second = first + 1, third = second + 1;

    for(int i = 1; i <= number_Of_Combinations; i++){
        //for each combination of 3 elements
        if(second == size - 1){
            first++;
            second = first + 1;
            third = second + 1;
        }

        if(is_triangle_possible(array_1[first], array_1[second], array_1[third++]))
        countTriangle++;
        
        if(third == size){
            second++;
            third = second + 1;
        }

    }

    free(array_1);
    printf("Number of triangles that can be formed: %d\n", countTriangle);
    return 0;

}