//using quicksort algorithm to sort the alphabets

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *ch1, char *ch2){

    char temp = *ch1;
    *ch1 = *ch2;
    *ch2 = temp;

}

int partition(char *str, int low, int high){

    char pivot = str[high];
    int swapping_index = low;

    for(int i = low; i < high; i++){
        if(str[i] < pivot){
            swap(&str[i], &str[swapping_index]);
            swapping_index++;
        }
    }

    swap(&str[high], &str[swapping_index]);

    return swapping_index;

}

void quicksort(char *str, int low, int high){

    if(low < high){

        int pivot_position = partition(str, low, high);
        quicksort(str, low, pivot_position - 1);
        quicksort(str, pivot_position + 1, high);

    }
    else{
        return;
    }
}

// int compare(const void *a, const void *b){
//     return *(const char *)a - *(const char *)b;
// }

int main() {

    char *str = malloc(27 * sizeof(char));
    strcpy(str, "QWERTYUIOPLKJHGFDSAZXCVBNM");

    quicksort(str, 0, 25);
    // qsort(str, 26, sizeof(char), compare);

    printf("%s",str);

    free(str);

    return 0;
}