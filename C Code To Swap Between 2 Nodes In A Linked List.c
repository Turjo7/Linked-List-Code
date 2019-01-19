#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node *next;
};


void swapNodes(struct node **head_ref, int x, int y)
{

   if (x == y) return;


   struct node *prevX = NULL, *currX = *head_ref;
   while (currX && currX->data != x)
   {
       prevX = currX;
       currX = currX->next;
   }


   struct node *prevY = NULL, *currY = *head_ref;
   while (currY && currY->data != y)
   {
       prevY = currY;
       currY = currY->next;
   }


   if (currX == NULL || currY == NULL)
       return;


   if (prevX != NULL)
       prevX->next = currY;
   else
       *head_ref = currY;


   if (prevY != NULL)
       prevY->next = currX;
   else
       *head_ref = currX;


   struct node *temp = currY->next;
   currY->next = currX->next;
   currX->next  = temp;
}


void enter(struct node** head_ref, int new_data)
{

    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));


    new_node->data  = new_data;


    new_node->next = (*head_ref);

    (*head_ref)    = new_node;
}


void printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}


int main()
{
    struct node *start = NULL;


    enter(&start,14 );
    enter(&start,20 );
    enter(&start,13 );
    enter(&start,12 );
    enter(&start,15 );
    enter(&start,10 );


    printf("\n Linked list before swap\n");
    printList(start);

    swapNodes(&start, 12, 20);

    printf("\n Linked list after  swap\n");
    printList(start);

    return 0;
}
