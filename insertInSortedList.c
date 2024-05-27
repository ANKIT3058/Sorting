#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*first=NULL;

void create(int A[],int n)
{
    struct node *t,*last=NULL;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void display(struct node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

void insert(int key)
{
    struct node *p=first,*q=NULL;
    while(p->data<key)
    {
        q=p;
        p=p->next;
    }
    struct node *t=(struct node *)malloc(sizeof(struct node));
    t->data=key;
    t->next=q->next;
    q->next=t;
}

int main()
{
    int A[]={2,5,9,11,15},n=5;
    create(A,n);

    insert(10);
    display(first);
    return 0;
}