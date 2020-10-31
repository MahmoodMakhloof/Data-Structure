#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node* next;
}node;

node *create_newNODE()
{
	node *n=(node*)malloc(sizeof(node));
	return n;
}

void insert_nodeFIRST(node **head,int item)
{
	node* n=create_newNODE();
	if(*head==NULL) //rev
	{
		*head=n;
		n->val=item;
		n->next=NULL;
	}
	else
	{
		n->val=item;
		n->next=*head;
		*head=n;
	}
}

void insert_nodeLAST(node *head ,int item)
{
	node *n=create_newNODE();
	node *current =head;
	while(current->next!=NULL)
	{
		current=current->next;
	}
	n->val=item;
	current->next=n;
	n->next=NULL;
}

void insert_nodeAFTER(node *head ,int item ,unsigned int pos)
{
	if(pos<1)
	{
		printf("Position should be greater than zero !\n");
		return;
	}
	node* n=create_newNODE();
	node *current=head;
	int i;
	for(i=0;i<pos;i++)
	{
		current=current->next;
		if(current==NULL)
		{
			printf("invalid position\n");
			return;
		}
	}
	n->next=current->next;
	current->next=n;
	n->val=item;
}

void removeFIRST(node **head)
{
	if(*head==NULL)
	{
		printf("The list is empty!\n");
		return;
	}
	node* rem=*head;
	*head=rem->next;
	printf("%d is removed\n",rem->val);
	free(rem);
}

void removeLAST(node *head)
{
	if(head==NULL)
	{
		printf("The list is empty!\n");
		return;
	}
	node *before_rem=head;
	while(before_rem->next->next!=NULL)
	{
		before_rem=before_rem->next;
	}
	printf("%d is removed\n",before_rem->next->val);
	free(before_rem->next);
	before_rem->next=NULL;
}

void removeAFTER(node*head,unsigned int pos)
{
	if(pos<1)
	{
		printf("Position should be greater than zero !\n");
		return;
	}

	if(head==NULL)
	{
		printf("The list is empty!\n");
		return;
	}
	node *rem=head;
	node *current;
	int i;
	for(i=0;i<=pos;i++)
	{
		current=rem;
		rem=rem->next;
	}
	current->next=rem->next;
	printf("%d is removed\n",rem->val);
	free(rem);
}

void printLIST(node *head)
{
	if(head==NULL)
	{
		printf("Can't print list ,the list is empty!\n");
		return;
	}
	node *current=head;
	while(current!=NULL)
	{
		printf("%d\t",current->val);
		current=current->next;
	}
	printf("\n");
}

int main()
{
	//initial the list by NULL
	node *head=NULL;

	//insert nodes
	insert_nodeFIRST(&head,1);
	insert_nodeFIRST(&head,2);
	insert_nodeFIRST(&head,3);
	insert_nodeLAST(head,4);
	insert_nodeAFTER(head,5,1);

	//print list
	printLIST(head);

	//remove nodes
	removeFIRST(&head);
	removeLAST(head);
	removeAFTER(head,1);

	//print list
	printLIST(head);

}
