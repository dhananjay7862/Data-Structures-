#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *pre;
	int data;
	struct node *next;
}*head=NULL,*newnode,*temp;
struct node * createnewnode(int n)
{
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	nn->pre=NULL;
	nn->data=n;
	nn->next=NULL;
	return nn;
}
void insertatbeg(int n)
{
	newnode=createnewnode(n);
	if(head==NULL)
		head=newnode;
	else
	{
		newnode->next=head;
		head->pre=newnode;
		head=newnode;
	}
}
void traverse()
{
	printf("\nForward Traversal\n");
	struct node *r;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		if(temp->next==NULL)
			r=temp;
		temp=temp->next;
	}
	printf("\nBackword Direction:\n");
	while(r!=NULL)
	{
		printf("%d\t",r->data);
		r=r->pre;
	}
}

void insertatlast(int n)
{
	newnode=createnewnode(n);
	if(head==NULL)
		head=newnode;
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->pre=temp;
	}
}
void insertbefore(int source,int n)
{
	temp=head;
	int found=0;
	while(temp!=NULL)
	{
		if(temp->data==source)
		{
			newnode=createnewnode(n);
			newnode->pre=temp->pre;
			newnode->next=temp;
			temp->pre->next=newnode;
			temp->pre=newnode;
			found=1;
			break;
		}
		temp=temp->next;
	}
	if(found==0)
		printf("\nSource Number Not Found\n");
}
void deleteatbeg()
{
	if(head==NULL)
	{
		printf("\nList is Empty");
	}
	temp=head;
	head=head->next;
	head->pre=NULL;
	printf("\nNumber to Be Deleted = %d",temp->data);
	free(temp);
}
void deleteatlast()
{
	if(head==NULL)
	{
		printf("\nList is Empty\n");
	}
	temp=head;
	if(head->next==NULL)
	{
		temp=head;
		head=NULL;
		printf("\nNumber to Be Deleted=%d",temp->data);
		free(temp);
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->pre->next=NULL;
		printf("\nNumber To Be Deleted = %d",temp->data);
		free(temp);
	}
}
int main()
{
	insertatbeg(10);
	insertatbeg(5);
	insertatbeg(2);
	insertatlast(30);
	insertatlast(40);
	insertbefore(30,25);
	traverse();
	deleteatlast();
	traverse();
}
