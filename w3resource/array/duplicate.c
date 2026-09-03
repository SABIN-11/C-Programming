#include <stdio.h>
#include <stdlib.h>

// int countDuplicate(int *array, int *freq, int n){

//    int count=0;

//    for(int i = 0; i < n; i++){
//       if(!(*(freq + i))){
//          for(int j = i + 1; j < n; j++){
//             if(array[i] == array[j]){
//                freq[j]=1;  //flaging 1 for duplicate elements except one
//                freq[i]=2;  //flaging 2 for that remaining one
//             }
//          }
//       }
//    }

//    for(int i = 0; i < n; i++)
//    if(freq[i] == 2)
//    count++;

//    return count;
// }
void unique(int *array, int *freq, int n){

   for(int i = 0; i < n; i++){
      if(!freq[i]){
         for(int j = i + 1; j < n; j++){
            if(array[i] == array[j]){
               freq[j]=1;  //flaging 1 for duplicate elements
               freq[i]=1;  
            }
         }
      }
   }
   printf("Unique:\n");
   for(int i = 0; i < n; i++)
   if(freq[i] == 0)
   printf("%d\t",array[i]);

   
}

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
      
   int *frequency = (int*)calloc(number, sizeof(int));
   if (frequency == NULL) {
      printf("Error while allocating the memory");
      exit(1);
   }

   // printf("There are total %d duplicate elements",countDuplicate(array, frequency, number));
   unique(array, frequency, number);
    // Free the allocated memory
   free(array);
   free(frequency);

   return 0;
}

