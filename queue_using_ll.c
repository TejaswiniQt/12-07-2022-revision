/****************program to implement queue using linked list******************************/


#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
}queue;

void enque(queue **front,queue **rear,int data);
void deque(queue **front,queue **rear);
void print(queue **front,queue **rear);

int main()
{
	queue *front = NULL, *rear = NULL;
	int option,data;
	while(1)
	{
		printf("1.Enque\n2.Deque\n3.Print\n4.Exit\n");
		printf("Enter the option:");
		scanf("%d",&option);
		switch(option)
		{
			case 1:printf("Enter data to be inserted:");
			       scanf("%d",&data);
			       enque(&front,&rear,data);
			       break;
			case 2:deque(&front,&rear);
			       break;
			case 3:print(&front,&rear);
			       break;
			case 4:exit(0);
			       break;
			default : printf("Invalid option\n");
		}
	}
	return 0;
}

void enque(queue **front,queue **rear,int data)
{
	queue *new = (queue *) malloc(sizeof(queue));
	if(new == NULL)
	{
		printf("Memory is not allocated\n");
	}
	else
	{
		new->data = data;
		new->link = NULL;
		if(*front == NULL && *rear == NULL)
		{
			*front = new;
			*rear = new;
		}
		else
		{
			(*rear)->link = new;
			*rear = new;
		}
	}
}


void deque(queue **front,queue **rear)
{
	if(*front == NULL && *rear == NULL)
	{
		printf("Queue is empty\n");
	}
	else
	{
		queue *temp = *front;
		*front = temp->link;
		if(*front == NULL)
			*rear = NULL;
		printf("The dequeued element is %d\n",temp->data);
		free(temp);
	}
}

void print(queue **front,queue **rear)
{
	queue *temp = *front;
	if(*front == NULL && *rear == NULL)
	{
		printf("Queue is empty\n");
	}
	else
	{
		while(temp != NULL)
		{
			printf("%d ",temp->data);
			temp = temp->link;
		}
		printf("\n");
	}
}

