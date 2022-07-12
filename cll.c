/****************program to implement circular linked list******************************/


#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
}cll;

void insert(cll **head,int data);
void print(cll **head);

int main()
{
	cll *head = NULL;
	int option,data;
	while(1)
	{
		printf("1.Insert\n2.print\n3.exit\n");
		printf("Enter the option:");
		scanf("%d",&option);
		switch(option)
		{
			case 1:printf("Enter data to be inserted:");
			       scanf("%d",&data);
			       insert(&head,data);
			       break;
			case 2:print(&head);
			       break;
			case 3:exit(0);
			       break;
			default : printf("Invalid option\n");
		}
	}
	return 0;
}

void insert(cll **head,int data)
{
	cll *new = (cll *) malloc(sizeof(cll));
	if(new == NULL)
	{
		printf("Memory is not allocated\n");
	}
	else
	{
		new->data = data;
		new->link = NULL;
		if(*head == NULL)
		{
			*head = new;
			new->link = *head;
		}
		else
		{
			cll *temp = *head;
			while(temp->link != *head)
			{
				temp = temp->link;
			}
			temp->link = new;
			new->link = *head;
		}
	}
}

void print(cll **head)
{
	cll *temp = *head;
	if(*head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		while(temp->link != *head)
		{
			printf("%d ",temp->data);
			temp = temp->link;
		}
		printf("%d\n",temp->data);
	}
}

