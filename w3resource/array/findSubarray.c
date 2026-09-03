/*finding the subarray to form a target sum*/
#include <stdio.h>
#include <stdlib.h>


void findSubarray(int i, int targetSum, int number, int *array){

    int j,current_Sum=0, flag = 0;
    if(i >= number){
        return;
    }

    for(j = i; j < number; j++){
        current_Sum+=array[j];
        if(current_Sum > targetSum){
            current_Sum = 0;
            break;
        }
        else if(current_Sum == targetSum){
            flag = 1;
            break;
        }
    }

    if(flag == 0)
    findSubarray(i + 1, targetSum, number, array);

    else{
        printf("Sub array is:\t");
        while(i <= j){
            printf("%d\t",array[i++]);
        }
    }
}

void frequencyOfX(int *array, int number){
    int value,ctr=0;

    printf("Enter the value whose frquency is to be checked:");
    scanf("%d",&value);

    for(int i = 0; i < number; i++){
        if(array[i] == value)
        ctr++;
    }

    if(ctr > number / 2)
    printf("%d occurs more than %d times.",value, number / 2);

}

int main() {
   int number,targetSum;

   printf("Enter the number of elements you want in the array: ");
   scanf("%d", &number);

   int *array = (int*)malloc(number * sizeof(int));

   if (array == NULL) {
        printf("Error while allocating the memory");
        exit(1);
   }

   for (int i = 0; i < number; i++)
        scanf("%d", array + i);

    // printf("Enter the target to find:");
    // scanf("%d",&targetSum);

    // findSubarray(0, targetSum, number, array);
    frequencyOfX(array, number);

    // Free the allocated memory
   free(array);

   return 0;
}


