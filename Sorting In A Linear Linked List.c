#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node *next;
};


void insert(struct node **start_ref, int data);


void Sort(struct node *start);


void swap(struct node *a, struct node *b);


void printList(struct node *start);

int main()
{
    int arr[50];
    int list_size, i;


    struct node *start = NULL;


    for (i = 0; i< 50; i++)
        insert(&start, arr[i]=rand()%100);


    printf("\n Linked list before sorting\n\n ");
    printList(start);


    Sort(start);


    printf("\n Linked list after sorting\n\n ");
    printList(start);

    getchar();
    return 0;
}



void insert(struct node **start_ref, int data)
{
    struct node *ptr1 = (struct node*)malloc(sizeof(struct node));
    ptr1->data = data;
    ptr1->next = *start_ref;
    *start_ref = ptr1;
}


void printList(struct node *start)
{
    struct node *temp = start;
    printf("\n");
    while (temp!=NULL)
    {
        printf("->%d\t", temp->data);
        temp = temp->next;
    }
}


void Sort(struct node *start)
{
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;


    if (ptr1 == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}


void swap(struct node *a, struct node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
