/*
  Copyright (c) 2022 QILU UNIVERSITY OF TECHNOLOGY,
  FACULTY OF COMPUTER SCIENCE AND TECHNOLOGY,
  DUYU.(NO.202103180009).
  
  Source code file of Queue.
  October 3rd, 2022.
*/

#include<bits/stdc++.h>
#define SUCCESS 0
#define ERR_ERROR 1
#define ERR_OVERFLOW -1
#define MAX_QUEUE_SIZE 8
using namespace std;
typedef int Status;
typedef int ElemType;
typedef struct QueueMeta
{
	ElemType *base;
	int front;
	int rear;
}Queue;

Status InitQueue(Queue &Q)
{
	Q.base=new ElemType[MAX_QUEUE_SIZE];
	if(!Q.base) return ERR_OVERFLOW;
	else
	{
		Q.front=Q.rear=0;
	}
	return SUCCESS;
}

Status ClearQueue(Queue &Q)
{
	Q.front=Q.rear=0;
	return SUCCESS;
}

Status EnQueue(Queue &Q,ElemType e)
{
	if((Q.rear+1)%MAX_QUEUE_SIZE==Q.front) return ERR_ERROR;
	else
	{
		Q.base[Q.rear]=e;
		Q.rear=(Q.rear+1)%MAX_QUEUE_SIZE;
	}
	return SUCCESS;
}

bool isEmptyQueue(Queue Q)
{
	return Q.rear==Q.front;
}

bool isFullQueue(Queue Q)
{
	return Q.front==(Q.rear+1)%MAX_QUEUE_SIZE;
}

ElemType DeQueue(Queue &Q)
{
	if(Q.rear==Q.front) return (ElemType)ERR_ERROR;
	else
	{
		ElemType e=Q.base[Q.front];
		Q.front=(Q.front+1)%MAX_QUEUE_SIZE;
		return e;
	}
}

ElemType GetQueueHead(Queue Q)
{
	if(Q.front==Q.rear) return (ElemType)ERR_ERROR;
	return Q.base[Q.front];
}

int GetQueueLength(Queue Q)
{
	int t=Q.rear-Q.front;
	if(t>=0) return t;
	else return MAX_QUEUE_SIZE-t;
}

Status TraverseQueue(Queue Q)
{
	int p=Q.front;
	while(p!=Q.rear)
	{
		cout << Q.base[p] << endl;
		p=(p+1)%MAX_QUEUE_SIZE;
	}
	return SUCCESS;
}

Status DestoryQueue(Queue &Q)
{
	delete(Q.base);
	Q.rear=Q.front=0;
	return SUCCESS;
}

//Demo.
int main(void)
{
	Queue Q;
	InitQueue(Q);
	EnQueue(Q,1);
	TraverseQueue(Q);
	return 0;
}

/*
  End of Source code of Queue.
  Oct. 3rd, 2022 - v1.0.
*/
