//How do you find the intersection of two arrays?

#include<stdio.h>
#include<stdbool.h>

// Function prototypes
void input(int, int, int[], int[], bool[], int[]);
void intersection(int, int, int[], int[], bool[], int[]);
void frequency(int, int[], int[]);

int main() {
    int size_1;
    int size_2;

    printf("Enter the size of the first array: ");
    scanf("%d", &size_1);

    printf("Enter the size of the second array: ");
    scanf("%d", &size_2);

    int array_1[size_1];
    int array_2[size_2];

    bool isUnique[size_1];
    int freq[size_1];

    // Calling for input
    input(size_1, size_2, array_1, array_2, isUnique, freq);
    frequency(size_1, array_1, freq);
    intersection(size_1, size_2, array_1, array_2, isUnique, freq);

    return 0;
}

void input(int size_1, int size_2, int array_1[], int array_2[], bool isUnique[], int freq[]) {

    // Taking elements as an input for the first array
    printf("Enter %d elements for the first array:\n", size_1);
    for (int i = 0; i < size_1; i++) {

        printf("Element[%d]: ", i);
        scanf("%d", &array_1[i]);

        isUnique[i] = true; // Initialize isUnique array assuming all elements are unique
        freq[i] = 1; // Initialize frequency to 1 for each element

    }

    // Taking elements as an input for the second array
    printf("Enter %d elements for the second array:\n", size_2);
    for (int i = 0; i < size_2; i++) {

        printf("Element[%d]: ", i);
        scanf("%d", &array_2[i]);

    }
}

void intersection(int size_1, int size_2, int array_1[], int array_2[], bool isUnique[], int freq[]) {

    printf("Intersection elements of both arrays:\n");
    for (int i = 0; i < size_1; i++) {

        if (isUnique[i] && freq[i] == 1) { // Check if element is unique in array_1

            for (int j = 0; j < size_2; j++) {

                if (array_1[i] == array_2[j]) {

                    printf("%d\t ", array_1[i]); // Print the common element
                    isUnique[i] = false; // Mark as not unique
                    break; // Break inner loop as we found a match

                }
            }
        }
    }
    printf("\n");
}

void frequency(int size_1, int array_1[], int freq[]) {
    // Count frequency of each element in array_1
    for (int i = 0; i < size_1; i++) {

        for (int j = i + 1; j < size_1; j++) {

            if (array_1[i] == array_1[j])   freq[i]++;
                
        }
    }
}