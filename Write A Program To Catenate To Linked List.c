#include <stdio.h>
#include <stdlib.h>

struct number1{
    int odd;
    struct odd *next;
};

struct number2{
    int even;
    struct even *next;
};

struct number1 *start1;
struct number2 *start2;
struct number1 *temp1;
struct number2 *temp2;
struct number1 *last1;
struct number2 *last2;
int n;

void insert1(){
    int a;
    printf("Insert : ");
    scanf("%d",&a);
    last1 = start1;

    temp1=malloc(sizeof(struct number1));
    temp1->odd = a;
    temp1->next=NULL;

    if(start1==NULL){
        start1 = temp1;
    }
    else{
        while(last1->next!=NULL){
            last1 = last1->next;
        }
        last1->next =temp1;
    }
}

void insert2(){
    int a;
    printf("Insert : ");
    scanf("%d",&a);
    last2 = start2;

    temp2=malloc(sizeof(struct number2));
    temp2->even = a;
    temp2->next=NULL;

    if(start2==NULL){
        start2 = temp2;
    }
    else{
        while(last2->next!=NULL){
            last2 = last2->next;
        }
        last2->next =temp2;
    }
}



void printLinkedList1(){
    struct number1 * printVariable;
    printVariable=start1;

    printf("\nThe list  is : ");
    while(printVariable!=NULL){
        printf("%d ",printVariable->odd);
        printVariable = printVariable->next;
    }

}

void printLinkedList2(){
    struct number2 * printVariable;
    printVariable=start2;

    printf("\nThe list  is : ");
    while(printVariable!=NULL){
        printf("%d ",printVariable->even);
        printVariable = printVariable->next;
    }

}

void addLinkedList(){
    struct number1 * searchVariable1;
    struct number2 * searchVariable2;

     while(last1->next!=NULL){
            last1 = last1->next;
        }
    last1->next=start2;
    printLinkedList1();
}


int main(){

    printf("Insert In The First Link List : \n");
    while(1){
        printf("\nPress 1 To Insert\nPress 0 To Exit\n");
        scanf("%d",&n);
        if(n!=0){
            insert1();
        }
        else{
            break;
        }
    }

    printf("Insert In The Second Link List  : \n");
    while(1){
        printf("\nPress 1 To Insert\nPress 0 To Exit\n");
        scanf("%d",&n);
        if(n!=0){
            insert2();
        }
        else{
            break;
        }
    }
    printf("\n\n");
    printLinkedList1();
    printLinkedList2();
    addLinkedList();
    printf("\n\n");
    return 0;
}

