#include<stdio.h>
#define max 100
int insert_array(int lb,int ub,int a[],int pos,int m)
{
    int i=0;
    if(pos>ub||pos<lb)
    {
        printf("Wrong position selection!!!");
    }
    else
    {
        for(i=ub;i>=pos;i--)
        {
            a[i+1]=a[i];
        }
        a[pos-1]=m;
        ub++;
    }
    return ub;
}
int main()
{
    int a[max],i,n=0,pos=0,m=0;
    printf("Enter the number of elements to be stored:\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the position:\n");
    scanf("%d",&pos);
    printf("Enter the item:\n");
    scanf("%d",&m);
    n=insert_array(0,n,a,pos,m);
    printf("\nThe new array list is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
