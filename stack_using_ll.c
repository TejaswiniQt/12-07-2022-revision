/****************program to implement stack using linked list******************************/


#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
}stack;

void push(stack **top,int data);
void pop(stack **top);
void print(stack **top);

int main()
{
	stack *top = NULL;
	int option,data;
	while(1)
	{
		printf("1.Push\n2.Pop\n3.print\n4.exit\n");
		printf("Enter the option:");
		scanf("%d",&option);
		switch(option)
		{
			case 1:printf("Enter data to be inserted:");
			       scanf("%d",&data);
			       push(&top,data);
			       break;
			case 2:pop(&top);
			       break;
			case 3:print(&top);
			       break;
			case 4:exit(0);
			       break;
			default : printf("Invalid option\n");
		}
	}
	return 0;
}

void push(stack **top,int data)
{
	stack *new = (stack *) malloc(sizeof(stack));
	if(new == NULL)
	{
		printf("Memory is not allocated\n");
	}
	else
	{
		new->data = data;
		new->link = NULL;
		if(*top == NULL)
		{
			*top = new;
		}
		else
		{
			new->link = *top;
			*top = new;
		}
	}
}


void pop(stack **top)
{
	if(*top == NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		stack *temp = *top;
		*top = temp->link;
		printf("The popped element is %d\n",temp->data);
		free(temp);
	}
}

void print(stack **top)
{
	stack *temp = *top;
	if(*top == NULL)
	{
		printf("Stack is empty\n");
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

