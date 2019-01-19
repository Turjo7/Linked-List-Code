#include<stdio.h>
#include<stdlib.h>


struct list {
    int data;
    struct list *next;
};
typedef struct list node;

void display(node *head);

int main(void){
    node *start,*prev,*temp;
    int ans;
    start=(node*)malloc(sizeof(node));
    start->next=NULL;
    prev=start;
    do{
        fflush(stdout);
        printf("\n Press 1 To Create A Link List,Press 0 To Stop: ");
        fflush(stdin);
        scanf("%d",&ans);
        if(ans==1){
            temp=(node*)malloc(sizeof(node));
            fflush(stdout);
            printf("\nEnter Data: ");
            fflush(stdin);
            scanf("%d",&temp->data);
            temp->next=NULL;
            prev->next=temp;
            prev=temp;
            }

        }while(ans==1);
        display(start);


    return 0;
}
void display(node *head){
    node *temp;
    printf("\n Created Linked List: ");
    temp=head->next;
    while(temp!=NULL){
        printf("->%d\t",temp->data);
        temp=temp->next;
    }
    return;
}


