//find the second largest element in an array

// #include<stdio.h>
// #include<limits.h>

// void input(int,int[]);
// int secondLargest(int,int[]);

// int main(){

//     int size,arr[100];

//     printf("Enter the size of the array:");
//     scanf("%d",&size);
    
//     do {

//         printf("Enter the size of the array (must be greater than 2): ");
//         scanf("%d", &size);

//     if (size <= 2) {

//             printf("Array must contain at least 3 elements.\n\n");
//         }

//     } while (size <= 2);

//     input(size,arr);
//     printf("%d is the second largest element.",secondLargest(size,arr));

//     return 0;

// }

// void input(int size,int arr[]){

//     printf("Enter the elements:\n");

//     for(int i=0;i<size;i++){

//         printf("Element[%d]:",i);
//         scanf("%d",&arr[i]);

//     }

// }

// int secondLargest(int size,int arr[]){

//     int first,second;
//     first=second=INT_MIN;

//     for(int i=0;i<size;i++){

//         if(arr[i]>first){

//             second=first;
//             first=arr[i];
            
//         }

//         else if(arr[i]>second && arr[i]!=first){

//             second=arr[i];
//         }
//     }
//     return second;
// }

//merging two arrays together

// #include<stdio.h>
// #define n 100   //macro defining
// //function prototypes
// void input(int,int,int[],int[]);
// void merge(int,int,int[],int[]);
// void print(int,int[]);

// int main(){

//     int arr1[n],arr2[n];
//     int size1,size2;

//     printf("Enter the size for first and second arrays:");
//     scanf("%d%d",&size1,&size2);

//     if (size1 + size2 > n) {
//         printf("Error: Total size exceeds the maximum allowed size of %d.\n", n);
//         return 1;
//     }

//     input(size1,size2,arr1,arr2);//calling
//     merge(size1,size2,arr1,arr2);

//     return 0;

// }
// //for input of both arrays
// void input(int size1,int size2,int arr1[],int arr2[]){

//     printf("\nEnter the elements for first array:\n");

//     for(int i=0;i<size1;i++){

//         printf("Element[%d]:",i);
//         scanf("%d",&arr1[i]);

//     }

//     printf("Enter the elements for second array:\n");

//     for(int i=0;i<size2;i++){

//         printf("Element[%d]:",i);
//         scanf("%d",&arr2[i]);

//     }
// }
// //merging two arrays in 3rd array
// void merge(int size1,int size2,int arr1[],int arr2[]){

//     int size3=size1+size2;
//     int arr3[n]={};
//     int j=0;

//     for(int i=0;i<size1;i++){

//         arr3[j]=arr1[i];
//         j++;

//     }

//     for(int i=0;i<size2;i++){

//         arr3[j]=arr2[i];
//         j++;

//     }
    
//     print(size3,arr3);
// }
// //printing after merging
// void print(int size3,int arr3[]){

//     printf("Printing after merging first and second arrays:\n");
//     for(int i=0;i<size3;i++){

//         printf("%d\t",arr3[i]);

//     }
// }

//counting the words in a sentence

// #include<stdio.h>
// #include<string.h>
// #include<ctype.h>

// #define n 100

// int countWord(char str[]);
// int main(){

//     char str[n];

//     printf("Enter a sentence:");
//     fgets(str,n,stdin);
//     str[strcspn(str,"\n")]='\0';    //removing newline character

//     printf("There are total %d words.",countWord(str));
//     return 0;

// }

// int countWord(char str[]){
    
//     int count=1;    //inisialization the count to 1
//     int i=0;

//     while (isspace(str[i]))
//     {
//         i++;
//     }
    
//     while (str[i]!='\0')
//     {
//         if(!(isspace(str[i])) && isspace(str[i+1]))
//         count++;
//         i++;
//     }
    
//     return count;
// }


//binary search

#include<stdio.h>

// #define n 20    //defining macro

int binarySearch(int[],int,int);    //function prototype

int main(){

    int array[]={10,9,8,7,6,5,4,3,2,1};    //inisializing array with 10 elements 
    int target=9;
    int size=sizeof(array)/sizeof(array[0]);    //calculating the number of elements
    // int size=11;

    int index = binarySearch(array, target, size);

    if (index != -1) {

        printf("%d is at index %d\n", target, index);

    } else {

        printf("%d is not in the array\n", target);

    }

    return 0;

}

int binarySearch(int array[],int target,int size){

    int low=0,high=size-1;  //for finding the region to search
    int mid;

    while (low<=high)   
    {
        mid=(low+high)/2;   //finding the middle index

        if(target>array[mid])
        // low=mid+1;
        high=mid-1;

        else if(target<array[mid])
        // high=mid-1;
        low=mid+1;

        else 
        return mid; //target found

    }
    
    return -1;  //target not found
}

