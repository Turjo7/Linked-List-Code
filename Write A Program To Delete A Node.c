
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


void find()
{
	struct node *counter;
	int i=0,key;
	printf("Enter A Key\n");
	scanf("%d",&key);

	counter=root;    // assigning root to counter //

	while(counter!=NULL)
	{
		i++;
		if(counter->data==key)
		{
			printf("\nKey is at=%d \n\n",i);
			break;
		}
		else{
		counter=counter->next;
		}

	}
}
void del(){
    struct node *temp,*temp1;
    int item;
    printf("Enter An Item To Delete\n");
    scanf("%d",&item);
    temp=root;

    while((temp->next!=NULL)&&(temp->next->data!=item)){
        temp=temp->next;
    }
    temp1=(struct node*)malloc(sizeof(struct node));
    temp1=temp->next;
    temp->next=temp1->next;
    free(temp1);
    show();


}

int main()
{
    int key;

	while(1)
	{
		printf("Press <1> to Insert\nPress <2> to Display\nPress <3> to Delete a key\nPress <0> to Exit\n");
		scanf("%d",&n);
		if(n==1){
			insert();
		}
		if(n==2)
		{
			show();

		}
		if(n==3){
            del();   // find function calling //
		}
		if(n==0){
            break;
		}

	}
	return 0;
}




