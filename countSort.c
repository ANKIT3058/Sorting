#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#define I INT_MIN

int findMax(int A[], int n)
{
    int max=I;
    for(int i=0;i<n;i++)
    {
        if(max<A[i])
            max=A[i];
    }
    return max;
}

void CountSort(int A[], int n)
{
    int max,i,j;
    int *C;
    max=findMax(A,n);
    C=(int *)malloc(sizeof(int)*(max+1));

    for(i=0;i<max+1;i++)
        C[i]=0;

    for(i=0;i<n;i++)
        C[A[i]]++;

    i=0;j=0;
    while(i<max+1)
    {
        if(C[i]>0)
        {
            A[j++]=i;
            C[i]--;
        }
        else
            i++;
    }
}

int main()
{
    int A[]={6,3,9,10,15,6,8,12,3,6};
    CountSort(A,10);

    for(int i=0;i<10;i++)
        printf("%d ",A[i]);
    return 0;
}