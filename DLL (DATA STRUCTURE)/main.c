#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node* next;
	struct node* prev;
}node;

node *create_newNODE()
{
	node *n=(node*)malloc(sizeof(node));
	return n;
}

void insert_nodeFIRST(node **head,int item)
{
	node* n=create_newNODE();
	if(*head==NULL)
	{
		*head=n;
		n->val=item;
		n->next=NULL;
		n->prev=NULL;
	}
	else
	{
		n->val=item;
		n->next=*head;
		(*head)->prev=n;
		*head=n;
		n->prev=NULL;
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
	n->prev=current;
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
	for(i=1;i<pos;i++)
	{
		current=current->next;
		if(current==NULL)
		{
			printf("invalid position\n");
			return;
		}
	}
	n->next=current->next;
	current->next->prev=n;
	current->next=n;
	n->prev=current;
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
	(*head)->prev=NULL;
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

void deleteNode(struct node** head, struct node* del)
{
 /* base case */
 if (*head == NULL || del == NULL)
     return;

 /* If node to be deleted is head node */
 if (*head == del)
     *head = del->next;

 /* Change next only if node to be deleted is NOT the last node */
 if (del->next != NULL)
     del->next->prev = del->prev;

 /* Change prev only if node to be deleted is NOT the first node */
 if (del->prev != NULL)
     del->prev->next = del->next;
 /* print the item of node that deleted */
 printf("%d is removed\n",del->val);
 /* Finally, free the memory occupied by del*/
 free(del);
 return;
}

void removeAFTER(node**head,unsigned int pos)
{
	if(pos<1)
	{
		printf("Position should be greater than zero !\n");
		return;
	}

	if(*head==NULL)
	{
		printf("The list is empty!\n");
		return;
	}
	node *current=*head;
	int i;
	for(i=0;i<pos&&current!=NULL;i++)
	{
		current=current->next;
	}

	if(current==NULL)
	{
		printf("invalid position");
		return;
	}
	deleteNode(head,current);
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
	removeAFTER(&head,1);


	//print list
	printLIST(head);

}
