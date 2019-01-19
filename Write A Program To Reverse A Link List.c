
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


void rev(){
    struct node *a;
    struct node *b;
    struct node *c;
    a = root, b = NULL;

 while(a != NULL) {
  c = b, b = a, a = a->next;
  b->next = c;
      }

  root= b;
  show();
  }


int main()
{
    int key;

	while(1)
	{
		printf("Press <1> to Insert\nPress <2> to Display\nPress <3> to Reverse the link list\nPress <0> to Exit\n");
		scanf("%d",&n);
		if(n==1){
			insert();
		}
		if(n==2)
		{
			show();

		}
		if(n==3){
            rev();
		}
		if(n==0){
            break;
		}

	}
	return 0;
}




