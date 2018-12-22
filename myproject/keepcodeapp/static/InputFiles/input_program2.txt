#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int top=-1;
int n=7;
void push(int stack[],int data)
{
	if(top>=n)
	{
		printf("stack overflow:\n");
	}
	top=top+1;
	stack[top]=data;
	
}
int pop(int stack[])
{
	if(top<=-1)
	{
		printf("stack underflow:\n");
	}
	int y=stack[top];
	top-=1;
	return(y);
}
void display(int stack[])
{
	int i;
	for(i=0;i<=top;i++)
	{
		printf("%d ",stack[i]);
	}
}
main()
{
	int ch,da,g;
	int stack[n];
	while(1)
	{
		printf("enter your choise\n 1 for push and \n 2 for pop\n 3 for display\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter a data:\n");
				scanf("%d",&da);
				push(stack,da);
				break;
			case 2:
				 g=pop(stack);
				break;
			case 3:
				display(stack);
				break;
		}
	}
}
