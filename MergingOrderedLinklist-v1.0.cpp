/*
  Copyright (c) 2022 QILU UNIVERSITY OF TECHNOLOGY,
  FACULTY OF COMPUTER SCIENCE AND TECHNOLOGY,
  DUYU.(NO.202103180009).
  
  Source code file of MergingOrderedLinklist.
  October 26th, 2022.
 */

#include<bits/stdc++.h>
#define SUCCESS 0
#define ERR_ERROR 1
#define ERR_OVERFLOW -1
#define MAX_INTEGER 4294967295
#define MIN_NUMBER 1000000
using namespace std;
typedef int Status;
typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	LNode *next;
}LNode,*LinkList;

typedef struct DblLNode
{
	ElemType data;
	DblLNode *next;
	DblLNode *prior;
}DblLNode, *DblLinkList;

Status InitList(LinkList &L)
{
	L=new LNode;
	L->next=NULL;
	return SUCCESS;
}

Status InsertList_H(LinkList &L,ElemType e)
{
	int n;cin >> n;
	for(int i=0;i<=n-1;i++)
	{
		LNode *t,*p=new LNode;
		p->data=e;
		t=L->next;
		L->next=p;
		p->next=t;
	}
	return SUCCESS;
}

Status TraverseLinkList(LinkList L)
{
	LNode *p=L->next;
	while(p)
	{
		cout << p->data <<endl;
		p=p->next;
	}
	return SUCCESS;
}

Status InsertList_B(LinkList &L)
{
	LNode *t=L;
	int n;cin >> n;
	for(int i=0;i<=n-1;i++)
	{
		LNode *p=new LNode;
		cin >> p->data;
		p->next=NULL;
		t->next=p;
		t=p;
	}
	return SUCCESS;
}

Status MergingOrderedLinklist(LinkList A,LinkList B,LinkList &C)
{
	LNode *pa=A->next,*pb=B->next,*pc=C;
	while(pa&&pb)
	{
		if(pa->data<pb->data)
		{
			LNode *t=pc->next;
			LNode *q=pa;
			pc->next=pa;
			pa=pa->next;
			q->next=t;
		}
		else
		{
			LNode *t=pc->next;
			LNode *q=pb;
			pc->next=pb;
			pb=pb->next;
			q->next=t;
		}
	}
	while(pa)
	{
		LNode *t=pc->next;
		LNode *q=pa;
		pc->next=pa;
		pa=pa->next;
		q->next=t;
	}
	while(pb)
	{
		LNode *t=pc->next;
		LNode *q=pb;
		pc->next=pb;
		pb=pb->next;
		q->next=t;
	}
	return SUCCESS;
}
int main(void)
{
	LinkList A,B,C;
	InitList(A);InitList(B);InitList(C);
	InsertList_B(A);InsertList_B(B);
	MergingOrderedLinklist(A,B,C);
	TraverseLinkList(C);
	return 0-0;
}

/*
  End of Source code of Merging Ordered Linklist.
  Edit on October 24th, 2022 v1.0.
  Edit on October 26th, 2022 v1.1.
 */
