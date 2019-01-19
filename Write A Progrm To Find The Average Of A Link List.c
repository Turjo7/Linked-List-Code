#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct list {
    int data;
    struct list *next;
};
typedef struct list node;

int i=0;
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
                i++;
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
    int sum=0;
    printf("\n Created Linked List: ");
    temp=head->next;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        sum=sum+temp->data;
        temp=temp->next;



    }
    printf("The Sum Of The Link List :%d\t",sum);
    printf("The Average Of The Link List :%d\t",sum/i);


    return;
}



