#include<stdio.h>
#include<stdlib.h>
typedef struct node_type
{
	struct node_type *prev;
	int info;
	struct node_type *next;
}node;
node *start=NULL;
node *end=NULL;
void add_at_beginning()
{
	node *ptr,*loc;
	ptr=(node *)malloc(sizeof(node));
	if(ptr==NULL)
	{
		printf("no memory:\n");
		return;
	}
	printf("enter a data\n");
	scanf("%d",&(ptr->info));
	if(start==NULL)
	{
		start=ptr;
		ptr->next=NULL;
		ptr->prev=NULL;
		end=ptr;
	}
	else
	{
		ptr->next=start;
		ptr->prev=NULL;
		start=ptr;
	}
	
}
void display()
{
	node *ptr;
	ptr=start;
	while(ptr!=end)
	{
		printf("%d--->",ptr->info);
		ptr=ptr->next;
	}
	printf(" %d-----",ptr->info);
}
main()
{
	int choice;
	
	while(1)
	{
		printf("enter your choise:\n 1 for add node \n 2 for display node:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				add_at_beginning();
				break;
			case 2:
				display();
				break;
		}
	}
}
