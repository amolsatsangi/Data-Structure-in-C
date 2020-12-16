\* Traversal of array
Here the program is taking the input from user in an array and then traversing each and every element of array and printing it on screen.
*\
#include<stdio.h>
#define max 100
void Traversal_array(int lb,int ub,int a[])
{
    int i=0;
    printf("\nYou have entered the numbers:\n");
    for(i=lb;i<ub;i++)
    {
        printf("%d ",a[i]);
    }
}
int main()
{
    int a[max];
    int n,i;
    printf("Enter the number of elements you want to enter in array list.\n");
    scanf("%d",&n);
    printf("Enter the numbers:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    Traversal_array(0,n,a);
    return 0;
}
