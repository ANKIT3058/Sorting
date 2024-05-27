#include<stdio.h>

void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void selectionSort(int A[], int n)
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        for(j=k=i;j<n;j++)
        {
            if(A[j]<A[k])
                k=j;
        }
        swap(&A[k],&A[i]);
    }
}

int main()
{
    int A[]={8,6,3,2,5,4},n=6,i;

    selectionSort(A,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    return 0;
}