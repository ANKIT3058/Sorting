#include<stdio.h>

void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void BubbleSort(int A[], int n)
{
    int i,j,flag=0;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(A[j]>A[j+1])
            {
                flag=1;   
                swap(&A[j],&A[j+1]);
            }
        }
        if(flag==0)
            break;
    }
}

int main()
{
    int A[]={5,1,13,8,15,19,7,2},n=8,i;
    BubbleSort(A,n);
    
    for(i=0;i<n;i++)
        printf("%d ",A[i]);
    return 0;
}