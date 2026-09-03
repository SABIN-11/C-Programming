//finding maximum element in the array using pointer

// #include<stdio.h>
// void max(int*);
// void input();
// #define n 5
// int arr[n],*g;
// int main(){
    
//     printf("Enter %d elements:\n",n);
//     input();
//     max(arr);
//     printf("Maximum=%d",*g);
//     return 0;
// }

// void input(){
//     int *i;
//     int k=0;
//     for(i=arr;i<=arr+n-1;i++){
//         printf("Element[%d]:",k);
//         scanf("%d",i);
//         k++;
//     }
// }
// void max(int *j){
//     g=j;
//     for(int i=0;i<n;i++){
//         if(*g<*j){
//             *g=*j;
//         }
//         j++;
//     }
// }


//reversing an array using pointers


// #include<stdio.h>
// void reverse();
// #define n 5
// int arr[n];
// void input(){
//     int *i;
//     int k=0;
//     for(i=arr;i<=arr+n-1;i++){
//         printf("Element[%d]:",k);
//         scanf("%d",i);
//         k++;
//     }
// }

// int main(){
//     printf("Enter %d elements:\n",n);
//     input();
//     printf("Elements in reversed order:\n");
//     reverse(arr);
//     return 0;
// }
//  void reverse(int *j){
//     for(int i=0;i<n;i++){
//         printf("%d\t",*(j+n-1));
//         j--;
//     }
//  }


// #include<stdio.h>
// void main(){
//     char a[7];
//     fgets(a,sizeof(a),stdin);//taking input stdin:standard input aka keyboard
//     printf("%s",a);
// }


// #include <stdio.h>

// int main() {
//     int arr[5] = {1, 2, 3, 4, 5};
//     int *ptr = arr; // `ptr` points to the first element of `arr`

//     // Using array notation
//     printf("Array element 3: %d\n", arr[2]); // Output: 3

//     // Using pointer notation
//     printf("Pointer notation: %d\n", *(ptr + 2)); // Output: 3

//     // Sizeof operator differences
//     printf("Size of array: %zu\n", sizeof(arr)); // Output: size of the whole array
//     printf("Size of pointer: %zu\n", sizeof(ptr)); // Output: size of the pointer itself

//     return 0;
// }

#include<stdio.h>

void pointer(int **ptr,int *a);
int main(){

    int x=5;
    int y=10;

    int *p=&y;

    pointer(&p,&x);
    
    printf("%d %d",x,y);

    return 0;
}

void pointer(int **ptr,int *a){

    **ptr=15;
    *a=100;

}



