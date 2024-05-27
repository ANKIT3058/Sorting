#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    int data;
    struct node *next;
};

int findMax(int A[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
            max = A[i];
    }
    return max;
}

void insert(struct node **p, int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    if (*p == NULL)
    {
        *p = t;
    }
    else
    {
        struct node *q = *p;
        while (q->next)
        {
            q = q->next;
        }
        q->next = t;
    }
}

int Delete(struct node **p)
{
    struct node *q = NULL;
    struct node *temp = *p;
    int x = -1;

    if (*p == NULL)
        return x; // If the list is empty

    if ((*p)->next == NULL)
    {
        x = (*p)->data;
        free(*p);
        *p = NULL;
        return x;
    }

    while (temp->next)
    {
        q = temp;
        temp = temp->next;
    }
    q->next = NULL;
    x = temp->data;
    free(temp);
    return x;
}

void BinSort(int A[], int n)
{
    int max, i, j;
    struct node **Bins;
    max = findMax(A, n);
    Bins = (struct node **)malloc(sizeof(struct node *) * (max + 1));

    for (i = 0; i < max + 1; i++)
        Bins[i] = NULL;

    for (i = 0; i < n; i++)
        insert(&Bins[A[i]], A[i]);

    i = 0;
    j = 0;
    while (i < max + 1)
    {
        while (Bins[i] != NULL)
        {
            A[j++] = Delete(&Bins[i]);
        }
        i++;
    }

    free(Bins); // Don't forget to free the allocated memory
}

int main()
{
    int A[] = {6, 8, 3, 10, 15, 6, 9, 12, 6, 3};
    int n = sizeof(A) / sizeof(A[0]);
    BinSort(A, n);

    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    return 0;
}
