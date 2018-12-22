#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int item;
	struct node *next;
};
node* start,*end;
int count=0;
void add_at_beginning()
{
	node *ptr;
	ptr=(node*)malloc(sizeof(node));
	printf("enter a data:\n");
	scanf("%d",&(ptr->item));
	if(ptr==NULL)
	{
		return;
	}
	if(start==NULL)
	{
		ptr->next=ptr;
		end=start=ptr;
	
	}
	else
	{
		ptr->next=start;
		start=ptr;
		end->next=start;
	}
	count++;
}
void displaylist()
{
	node *ptr;
	ptr=start;
	if(ptr==NULL)
	{
		printf("no node:\n");
		return;
	}
	while(ptr!=end)
	{
		printf("%d->>",ptr->item);
		ptr=ptr->next;
	}
	printf("%d\n",ptr->item);
}
int fun1(node *ptr)
{
	printf("%d ",ptr->item);
	if(count%2!=0)
	{
		if(ptr!=end && ptr!=NULL)
		fun1(ptr->next->next);
		printf(" %d ",ptr->item);
    }
    else
    {
	    if(ptr->next!=end)
		fun1(ptr->next->next);
		printf(" %d ",ptr->item);
	}
}
void add_at_end()
{
	node* ptr,*loc;
	ptr=(node*)malloc(sizeof(node));
	if(ptr==NULL)
	{
		printf("no memory\n");
	}
	printf("enter a new  node data\n");
	scanf("%d",&(ptr->item));
	ptr->next=start;
	end->next=ptr;
	end=ptr;
}
void add_at_any()
{
	node*ptr,*loc;
	int info;
	ptr=(node*)malloc(sizeof(node));
	if(ptr==NULL)
	{
		printf("no memory\n");
		return;
	}
	loc=start;
	printf("enter a new node data:\n");
	scanf("%d",&(ptr->item));
	printf("enter a after a key node data:\n");
	scanf("%d",&info);
	while(loc->next->item!=info)
	{
		loc=loc->next;
	}
	ptr->next=loc->next;
	loc->next=ptr;
	
}
void delete_at_beginning()
{
	node *ptr;
	ptr=start->next;
	free(start);
	start=end->next=ptr;
}
void delete_at_any()
{
	node *ptr,*loc;
	int data;
	printf("enter a data you wnt to delete:\n");
	scanf("%d",&data);
	loc=start;
	while(loc->next->item!=data)
	{
		loc=loc->next;
	}
	ptr=loc->next->next;
	free(loc->next);
	loc->next=ptr;
}
void delete_at_end()
{
	node *ptr;
	ptr=start;
	while(ptr->next!=end)
	{
		ptr=ptr->next;
	}
	free(ptr->next);
	end=ptr;
	 ptr->next=start;
	 
}
main()
{
	int choise;

	while(1)
	{
		printf("enter your choise:\n");
		printf("1 for add_at_beginning\n 2 for displaylist\n 3 for print odd node\n 4 for add_at end \n 5 for delete at beginning \n 6 for delete at end \n 7 for add at any node \n 8 for delete any node\n 9 for exit(0)");
		scanf("%d",&choise);
		system("clear");
		switch(choise)
		{
			case 1:
				add_at_beginning();
				break;
			case 2:
				displaylist();
				break;
			case 3:
				fun1(start);
				printf("\n");
				break;
			case 4:
				add_at_end();
				break;
			case 5:
				delete_at_beginning();
				break;
			case 6:
				delete_at_end();
				break;
			case 7:
				add_at_any();
				break;
			case 8:
				delete_at_any();
				break;
			case 9:
		

		exit(0);
				break;
		}
	}
}
