// #include<stdio.h>
// #include<ctype.h>
// int main()
// {
//     char alp;
//     printf("Enter a alphabet:");
//     scanf("%c",&alp);
//     char cas=toupper(alp);
//     switch (cas)
//     {
//     case 'A':printf("Vowel");
//         break;
//     case 'E':printf("Vowel");
//     break;
//     case 'I':printf("Vowel");
//     break;
//     case 'O':printf("Vowel");
//     break;
//     case 'U':printf("Vowel");
//     break;
//     default:printf("Consonant");
//         break;
//     }
//     return 0;
// }

//sum of digits using recursion
// #include<stdio.h>
// int sum(int);
// int main()
// {
//     int num;
//     printf("Enter number:");
//     scanf("%d",&num);
//     printf("Sum of digits=%d",sum(num));
//     return 0;
// }
// int sum(int num)
// {
//     int rem;
//     static int s=0;
//     if(num>0)
//     {
//         rem=num%10;
//         s+=rem;
//         sum(num/10);
//     }
//     return s;
// }

//swapping using pointers
// #include<stdio.h>
// int main()
// {
//     int n1,n2;
//     printf("Enter two numbers:");
//     scanf("%d%d",&n1,&n2);
//     printf("Before swapping: n1=%d & n2=%d",n1,n2);
//     int *ptr1,*ptr2;
//     ptr1=&n1;
//     ptr2=&n2;
//     *ptr1=*ptr1+*ptr2;
//     *ptr2=*ptr1-*ptr2;
//     *ptr1=*ptr1-*ptr2;
//     printf("\nAfter swapping: n1=%d & n2=%d",*ptr1,*ptr2);
//     return 0;
// }

//deleting duplicate elements from the array

// #include<stdio.h>
// void input(int);
// void duplicate(int);
// #define n 10
// int a[n],b[n];
// int *p,*j;
// int main()
// {
//     int size;
//     printf("Enter the size:");
//     scanf("%d",&size);
//     printf("Enter the elements:\n");
//     input(size);
//     duplicate(size);
//     return 0;
// }
// void input(int size)
// {
//     int i=0;
//     for(p=a;p<=a+size-1;p++)
//     {
//         printf("Element-%d:",i);
//         i++;
//         scanf("%d",p);
//     }
// }
// void duplicate(int size)
// {
//     int x,i=0,ctr=0;
//     for(p=a;p<=a+size-1;p++)
//     {
//         x=0;
//         for(j=a;j<=a+size-1;j++)
//         {
//             if(p!=j)
//                 if(*p==*j)
//                 {
//                 x++;
//                 break;
//                 }
//         }
//         if(x==0)
//         {
//         b[i]=*p;
//         i++;
//         ctr++;
//         }
//     }
//     printf("After removing:\n");
//     for(p=b;p<=b+ctr-1;p++)
//     printf("%d\t",*p);

// }

//checking whether a matrix is a sparse matrix or not

#include<stdio.h>
#include<stdbool.h>
void input();
bool sparse();
#define n 3
int a[n][n],*i;
int main()
{
    printf("Enter the elements:\n");
    input();
    if(sparse())
    printf("It is a sparse matrix");
    else
    printf("It is not a sparse matrix");
    return 0;
}

void input()
{
    for(i=&a[0][0];i<=&a[n-1][n-1];i++)
    {
        scanf("%d",i);
    }
    
}
bool sparse()
{
    int ctr_num=0,ctr_zero=0;
    for(i=&a[0][0];i<=&a[n-1][n-1];i++)
    {
        if(*i>0)
        ctr_num++;
        else
        ctr_zero++;
    }
    if(ctr_zero>ctr_num)
    return 1;
    else
    return 0;
}