#include<stdio.h>
#define max 100

void BINARYSEARCH_ARRAY(int lb,int ub,int a[],int e)
{
    int i=0,k=0;
    for(i=lb;i<ub;i++)
    {
        if(a[i]==e)
        {
            k=i+1;
            break;
        }
    }
    if(k!=0)
    {
        printf("The element %d is found at location %d.\n",e,k);
    }
    else{
        printf("Element not found!!!");
    }
}
int main()
{
    int a[max],n,i,e;
    printf("Enter the number of elements to be stored:\n");
    scanf("%d",&n);
    printf("Enter the elements to be stored in array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the number to be searched:\n");
    scanf("%d",&e);
    BINARYSEARCH_ARRAY(0,n,a,e);
    return 0;
}
