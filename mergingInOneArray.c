#include<stdio.h>

void merge(int A[], int l, int mid, int h)
{
    int i,j,k;
    i=l;j=mid+1;k=l;
    int B[h+1];

    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }
    for(;i<=mid;i++)
        B[k++]=A[i];
    for(;j<=h;j++)
        B[k++]=A[j];
    for(i=l;i<=h;i++)
        A[i]=B[i];
}

int main()
{
    int A[]={2,5,8,12,3,6,7,10};
    merge(A,0,3,7);

    for(int i=0;i<=7;i++)
        printf("%d ",A[i]);
    return 0;
}