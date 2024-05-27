#include<stdio.h>

void Merge(int A[], int l, int mid, int h)
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

void MergeSort(int A[], int l, int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        MergeSort(A,l,mid);
        MergeSort(A,mid+1,h);
        Merge(A,l,mid,h);
    }
}

int main()
{
    int A[]={8,2,9,6,5,3,7,4};
    MergeSort(A,0,7);

    for(int i=0;i<8;i++)
        printf("%d ",A[i]);
    return 0;
}