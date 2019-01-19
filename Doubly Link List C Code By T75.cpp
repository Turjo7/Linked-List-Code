#include <stdio.h>
#include <stdlib.h>


struct node
{
	int value;
	struct node *next;
	struct node *prev;
};
struct node *head = NULL,*tail = NULL;
void insertfirst(int x);
void insertlast(int x);
void print();
int search(int x);
void remove(int x);
int length();
void rev();

int main()
{
	while(1)
	{
		printf("\t\t\t\t  ...MENU...\n");
		printf("\t\t\t\t(1) Insert First\n");
		printf("\t\t\t\t(2) Insert Last\n");
		printf("\t\t\t\t(3) Show All\n");
		printf("\t\t\t\t(4) Search\n");
		printf("\t\t\t\t(5) Remove\n");
		printf("\t\t\t\t(6) Length\n");
		printf("\t\t\t\t(7) Revers\n");
		printf("\t\t\t\t(8) Exit\n");
		printf("\t\t\t\t------------\n");
		printf("Enter Your Choice:");
		int choice;
		scanf("%d",&choice);
		system("cls");
		int x;
		switch(choice)
		{
			case 1:
					printf("Enter Number: ");
					scanf("%d",&x);
					insertfirst(x);
					print();
					break;
			case 2:
					printf("Enter Number: ");
					scanf("%d",&x);
					insertlast(x);
					print();
					break;
			case 3:
					print();
					break;
			case 4:
					printf("Search value : ");
					scanf("%d",&x);
					if(search(x))
						printf("Found\n");
					else
						printf("Not Found\n");
					break;
			case 5:
					printf("Which value you want to remove : ");
					scanf("%d",&x);
					remove(x);
					print();
					break;
			case 6:
					printf("length = %d\n",length());
					break;
			case 7:
					rev();
					break;
			case 8:
					exit(0);
		}
		getchar();
	}
}
void insertfirst(int x)
{
	node *temp= (node*)malloc(sizeof(node));
	if(head==NULL)
	{
		temp->prev=NULL;
		temp->value=x;
		temp->next=NULL;
		head=temp;
		tail=head;
	}
	else
	{
		temp->prev=NULL;
		temp->value=x;
		temp->next=head;
		head->prev=temp;
		head=temp;
	}
}
void print()
{
	node *currentnode=head;
	printf("\nYour List is: ");
	while(currentnode!=NULL)
	{
		printf("%d ",currentnode->value);
		currentnode= currentnode->next;
	}
	printf("\n\n\n");

}
void insertlast(int x)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	if(head==NULL)
	{
		temp->prev=NULL;
		temp->value=x;
		temp->next=NULL;
		head=temp;
		tail=temp;
	}
	else
	{
		temp->prev=tail;
		temp->value=x;
		temp->next=NULL;
		tail->next=temp;
		tail=temp;
	}
}
int search(int x)
{
	node *currentnode=head;
	while(currentnode!=NULL)
	{
		if(currentnode->value==x)
			return 1;
		currentnode= currentnode->next;
	}
	return 0;
}
int length()
{
	int l=0;
	node *currentnode=head;
	while(currentnode!=NULL)
	{
		l++;
		currentnode= currentnode->next;
	}
	return l;
}
void remove(int x)
{
	node *temp=NULL,*prev=NULL,*currentnode =head;
	if(search(x))
	{
		if(head->value==x)
		{
			if(head->next==NULL && head->prev==NULL)
			{
				head=NULL;
				tail=head;
				free(temp);
			}
			else
			{
				temp=head;
				head=head->next;
				head->prev=NULL;
				free(temp);
			}
		}
		else
		{
			while(currentnode!=NULL)
			{
				if(currentnode->value==x)
				{
					temp=currentnode;
					break;
				}
				else
					currentnode=currentnode->next;
			}
			if(temp->next==NULL && temp->prev!=NULL)
			{
				tail=temp->prev;
				tail->next=NULL;
				free(temp);
			}
			else
			{
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				free(temp);
			}
		}
	}
	else
		printf("Not found for remove");
}
void rev()
{
	node *correntnode=tail;
	while(correntnode!=NULL)
	{
		printf("%d\n",correntnode->value);
		correntnode=correntnode->prev;
	}
}
