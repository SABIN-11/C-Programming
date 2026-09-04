// #include<stdio.h>
// int main()
// {
//     int dc;
//     printf("Enter a number:");
//     scanf("%d",&dc);
//     for(int i=8;i>=0;i--)
//     {
//         if((1<<i)&dc)
//         printf("1");
//         else
//         printf("0");
//     }
//     return 0;
// }
#include<stdio.h>
int sum(int *);
void multiply(int *);
#define k 10
int *i,*p;
int main(){
    int n,num;
    int arr[k],j=0;
    printf("(1-3)Press 1 for the sum of arrays:\n");
    printf("Press 2 for the multiplication table:\n");
    printf("Press 3 to exit:\n");
    scanf("%d",&n);
    
    switch (n)
    {
    case 1:
    printf("Enter %d elements:\n",k);
    for(i=arr;i<=arr+k-1;i++){
        printf("Element-%d:",j);
        j++;
        scanf("%d",i);
    }
    printf("Sum of the elements you entered is %d",sum(arr));
    break;
    case 2:
    printf("Enter a number:");
    scanf("%d",&num);
    multiply(&num);
    break;
    case 3:
    break;
    default:printf("Invalid Input: Number must be within 1-3.");
}

    
return 0;
}
int sum(int *x){
    int s=0;
    for(p=x;p<=x+k-1;p++)
    {
        s+=*p;
    }
    return s;

}
void multiply(int *num){
    
    for(int j=1;j<=10;j++){
        
        printf("%d x %d : %d",*num,j,(*num)*j);
        printf("\n");
    }
}
