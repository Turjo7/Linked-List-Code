#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct list {
    int data;
    struct list *next;
};
typedef struct list node;

void display(node *head);


int main(void){
    node *start,*prev,*temp;
    char ans;
    start=(node*)malloc(sizeof(node));
    start->next=NULL;
    prev=start;
    do{
        fflush(stdout);
        printf("\n Do You Want To Create A Link List (Y/N): ");
        fflush(stdin);
        ans=toupper(getche());
        if(ans=='Y'){
            temp=(node*)malloc(sizeof(node));
            fflush(stdout);
            printf("\nEnter Data: ");
            fflush(stdin);
            scanf("%d",&temp->data);
            temp->next=NULL;
            prev->next=temp;
            prev=temp;
            }
        }while(ans=='Y');
        display(start);


    return 0;
}
void display(node *head){
    node *temp;
    int  max;
    printf("\n Created Linked List: ");
    temp=head->next;
    max=temp->data;
    while(temp!=NULL){


        if(temp->data>max){
            max=temp->data;
        }

        temp=temp->next;
        }






    printf("The Minimum Value In The Link List :%d\t",max);

    return;
}




