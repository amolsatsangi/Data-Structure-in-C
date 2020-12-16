#include<stdio.h>
void MERGE_ARRAY(int n,int a[],int m,int b[],int c[])
{
    int i=0,j=0,k=0;
    while(i<n||j<m)
    {
        if(a[i]<b[j])
        {
            c[k]=a[i];
            i++;
        }
        else
        {
            c[k]=b[j];
            j++;
        }
        k++;
    }
    while(i<n)
    {
        c[k]=a[i];
        k++;
        i++;
    }
    while(j<m)
    {
        c[k]=b[j];
        k++;
        j++;
    }
}
int main()
{
    int n,m,i;
    printf("Enter the number of elements of 1st array:\n");
    scanf("%d",&n);
    printf("Enter the number of elements of 2nd array:\n");
    scanf("%d",&m);
    int a[n],b[m],c[n+m];
    printf("Enter the elements of 1st array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the elements of 2nd array:\n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
    }
    MERGE_ARRAY(n,a,m,b,c);
    printf("The merged array is:\n");
    for(i=0;i<n+m;i++)
    {
        printf("%d ",c[i]);
    }
}
