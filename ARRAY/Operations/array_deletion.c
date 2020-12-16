#include<stdio.h>
#define max 100
int DELETION_ARRAY(int lb,int n,int pos,int a[])
{
    int i=0;
    if(pos>n||pos<=lb)
    {
        printf("Wrong position!!!\n");
    }
    else
    {
        for(i=pos;i<n;i++)
        {
            a[i-1]=a[i];
        }
        n--;
    }
    return n;
}
int main()
{
    int a[max],n,i,pos;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the position from where the element has to be deleted:\n");
    scanf("%d",&pos);
    n=DELETION_ARRAY(0,n,pos,a);
    printf("The new array is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
