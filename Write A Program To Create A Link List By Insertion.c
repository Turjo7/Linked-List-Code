
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *root;

int n;

void insert()
{
	int a;
	struct node *temp;               // pointer type structure//
	struct node *counter;
	counter=root;

	printf("Insert: ");
	scanf("%d",&a);

	temp=(struct node*)malloc(sizeof( struct node));
	temp->data=a;
	temp->next=NULL;

	if(root==NULL)                      // checking null//
	{
		root=temp;
	}
	else
	{
		while(counter->next!=NULL)
		{
			counter=counter->next;
		}
		counter->next=temp;
	}

}

void show()
{
	struct node *t;
	printf("The Linked List : ");
	t=root;
	while(t!=NULL)
	{
		printf("%d\t",t->data);
		t=t->next;
	}


}




void in(){
    struct node *temp;
    struct node *temp1;
    int item;
    printf("Do You Want To Insert An Item In Your Link List\n");
    scanf("%d",&item);
    temp=root;
    while((temp->next!=NULL) && (temp->next->data<item)){
        temp=temp->next;
    }
    temp1=(struct node*)malloc(sizeof(struct node));
    temp1->data=item;
    temp1->next=temp->next;
    temp->next=temp1;
    show();
}

int main()
{
    int key;

	while(1)
	{
		printf("\nPress 1 To Create A Link List\nPress 2 Show Your Link List\nPress 3 For Insert An Item And Insert The List\nPress 0 to EXIT\n");
		scanf("%d",&n);
		if(n==1){
			insert();
		}
		if(n==2)
		{
			show();

		}
		if(n==3){
            in();   // find function calling //
		}

		if(n==0){
            break;
		}

	}
	return 0;
}




