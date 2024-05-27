#include<stdio.h>

void insert(int A[], int n, int key)
{
    int i;
    for(i=n-1;i>=0;i--)
    {
        if(A[i]>key)
        {
            A[i+1]=A[i];
        }
        else
            break;
    }
    A[i+1]=key;
}

int main()
{
    int A[10]={1,3,5,12,18,20},n=6;
    insert(A,n,9);

    for(int i=0;i<7;i++)
        printf("%d ",A[i]);
    return 0;
}