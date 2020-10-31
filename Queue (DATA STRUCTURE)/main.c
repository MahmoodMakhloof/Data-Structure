#include <stdio.h>
#include <stdlib.h>

typedef enum boolean
{
	false,true
}bool;

typedef struct queue
{
	unsigned int capacity;
	int front;
	int rear;
	int *data;
}queue;

queue *create_QUEUE(unsigned int capacity)
{
	queue *QUEUE =(queue*)malloc(sizeof(queue));
	QUEUE->data=(int*)malloc(capacity*sizeof(int));
	QUEUE->rear=-1;
	QUEUE->front=0;
	QUEUE->capacity=capacity;
	return QUEUE;
}

bool isEmpty(queue *q)
{
	if(q->rear==-1)
		return true;
	else
		return false;
}

bool isFULL(queue *q)
{
	if(q->rear==q->capacity-1)
		return true;
	else
		return false;
}

void ENqueue(queue *q,int item)
{
	if(isFULL(q))
	{
		printf("The queue is full\n");
		return;
	}
	q->rear++;
	q->data[q->rear]=item;
	printf("%d is enqueued\n",q->data[q->rear]);
}

void DEqueue (queue *q)
{
	if(isEmpty(q))
	{
		printf("The queue is empty\n");
		return;
	}
	int i;
	printf("%d is dequeued\n",q->data[q->front]);
	for(i=q->front;i<q->rear;i++)
	{
		q->data[i]=q->data[i+1];
	}
	q->rear--;
}

void REenqueue (queue *q)
{
	if(isEmpty(q))
	{
		printf("The queue is empty\n");
		return;
	}
	int temp=q->data[q->front];
	DEqueue(q);
	ENqueue(q,temp);
}

int main ()
{
	queue *Q=create_QUEUE(5);

	ENqueue(Q,1);
	ENqueue(Q,2);
	ENqueue(Q,3);
	ENqueue(Q,4);
	ENqueue(Q,5);
	ENqueue(Q,6);

	int i;
	for(i=Q->front;i<=Q->rear;i++)
	{
		printf("%d\t",Q->data[i]);
	}
	printf("\n");

	REenqueue(Q);

	for(i=Q->front;i<=Q->rear;i++)
	{
		printf("%d\t",Q->data[i]);
	}

}
