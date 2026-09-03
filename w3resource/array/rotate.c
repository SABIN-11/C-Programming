/*rotate an array by n positions*/
#include <stdio.h>
#include <stdlib.h>

//function to right rotate an array
void rightRotate(int *array, int number){
    
    int positionToRightRotate,count = 0;
    printf("\nEnter the postion from which you want your array to be rotated:");
    scanf("%d",&positionToRightRotate);

    positionToRightRotate-=1;   //finding the index to rotate 

    for(int i = positionToRightRotate; i < number; i++){
        count++;    //counting how many elements to right rotate
    }

    //make a blank block of memory to right side of the last element
    int *array_2=(int *)realloc(array, (number + 1) * sizeof(int));

    while(count > 0){
        
        //right shift the elements
        for(int i = number; i > 0; i--)
        array_2[i] = array_2[i - 1];

        array_2[0]=array_2[number]; //store the last element in the first index

        count--;
    }

    
    //print the elements after rotation
    printf("\nArray after rotation\n");
    for(int i = 0; i < number; i++){
        printf("%d\t",array_2[i]);
    }

    free(array_2);

}

//0 3 6 9 12 14 18 20 22 25 27

int main() {
   int number;

   printf("Enter the number of elements you want in the array: ");
   scanf("%d", &number);

   int *array = (int*)malloc(number * sizeof(int));

   if (array == NULL) {
        printf("Error while allocating the memory");
        exit(1);
   }

   for (int i = 0; i < number; i++)
    scanf("%d", array + i);

    //printing the array before rotating
    printf("Array before rotation:\n");
    for(int i = 0; i < number; i++)
    printf("%d\t",array[i]);

    rightRotate(array, number);

    // Free the allocated memory
   free(array);

   return 0;
}