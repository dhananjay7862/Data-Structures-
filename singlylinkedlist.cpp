#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *link;
}*head=NULL,*temp,*newnode;
void insertatbeg(int num)
{
	newnode=(struct node *) malloc(sizeof(struct node));
	newnode->data=num;
	newnode->link=NULL;
	if(head==NULL)
		head=newnode;
	else
	{
		newnode->link=head;
		head=newnode;
	}
}
void traverse()
{
	printf("\nList Contains Following Data\n");
	temp=head;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->link;
	}
}
void insertatlast(int num)
{
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	newnode->link=NULL;
	if(head==NULL)
		head=newnode;
	else
	{
		temp=head;
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=newnode;
	}
}
void insertbefore(int source,int num)
{
	if(head==NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		int found=0;
		if(head->data==source)
		{
			newnode=(struct node *)malloc(sizeof(struct node));
			newnode->data=num;
			newnode->link=head;
			head=newnode;
			printf("\nNode Inserted");
			found=1;
		}
		else
		{
			temp=head;
			while(temp!=NULL)
			{
				if(temp->link->data==source)
				{
					newnode=(struct node *)malloc(sizeof(struct node));
					newnode->data=num;
					newnode->link=temp->link;
					temp->link=newnode;
					printf("\nNumber Inserted");
					found=1;
					break;
				}
				temp=temp->link;
			}
		}
		if(found==0)
			printf("\nSource Not Found");
		
	}
}
void deleteatbeg()
{
	if(head==NULL)
	{
		printf("\nList is Empty Unable to delete");
	}
	else
	{
		temp=head;
		head=head->link;
		printf("\nElement To Be Delete is : %d",temp->data);
		free(temp);
	}
}
void deleteatlast()
{
	if(head==NULL)
	{
		printf("\nList is empty, unable to Delete");
	}
	else
	{
		if(head->link==NULL)
		{
			temp=head;
			head=NULL;
			printf("\nNumber to Be Delete=%d",temp->data);
			free(temp);
		}
		else
		{
			temp=head;
			while(temp->link->link!=NULL)
			{
				temp=temp->link;
			}
			struct node *r=temp->link;
			temp->link=NULL;
			printf("\nNumber to Be Delete =%d",r->data);
			free(r);
		}
	}
}
int main()
{
	
	insertatbeg(10);
	insertatbeg(5);
	insertatbeg(2);
	insertatlast(20);
	insertatlast(30);
	insertbefore(20,15);
	traverse();
	deleteatlast();
	traverse();
	return 0;
}
