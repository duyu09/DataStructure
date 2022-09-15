// Copyright (c) 2022 Qilu University of Technology, Faculty of Computer Science & Technology, Duyu.(No.202103180009).
#include<bits/stdc++.h>
#define ERR_OVERFLOW -1
#define ERR_ERROR -2
#define SUCCESS 0
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

Status DblInitList(DblLinkList &L)
{
	L=new DblLNode;
	L->prior=NULL;
	L->next=NULL;
	return SUCCESS;
}

Status InsertList_H(LinkList &L)
{
	int n;cin >> n;
	for(int i=0;i<=n-1;i++)
	{
		LNode *t,*p=new LNode;
		cin >> p->data;
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

Status DeleteElem(LinkList &L,int index) 
//Index does not include head index.
{
	LNode *t,*p=L;int i=1;
	while(p && i<=index-1)
	{
		p=p->next;
		++i;
	}
	if(i<index-1 || !(p->next)) return ERR_ERROR;
	t=p->next;
	p->next=p->next->next;
	delete(t);
	return SUCCESS;
}

Status InsertElem(LinkList &L,int index)
{
	LNode *s,*t,*p=L;int i=1;
	while(p && i<=index-1)
	{
		p=p->next;
		++i;
	}
	if(i<index-1) return ERR_ERROR;
	s=new LNode;
	cin >> s->data;
	s->next=p->next;
	p->next=s;
	return SUCCESS;
}

ElemType GetElem(LinkList L,int index)
{
	LNode *p=L;int i=0;
	while(p && i<index)
	{
		p=p->next;
		++i;
	}
	if(i<index) return (ElemType)ERR_ERROR;
	else return p->data;
}

int GetIndex(LinkList L,ElemType elem)
{
	LNode *p=L->next;int i=1;
	while(p)
	{
		if(p->data==elem) return i;
		++i;p=p->next;
	}
	return (int)ERR_ERROR;
}

pair<int,int> GetMaximumElem(LinkList &L)
{
	int max=MIN_NUMBER;
	LNode *u=L->next;int t=0,i=1;
	while(u)
	{
		if(u->data>max)
		{
			max=u->data;
			t=i;
		}
		u=u->next;
		++i;
	}
	pair<int,int>temp;
	temp.first=max;
	temp.second=i;
	return temp;
}

Status ReverseLinkList(LinkList &L)
{
	LNode *head=L;
	L=L->next;
	LNode *r=L;
	LNode *p=L->next;
	LNode *t=NULL;
	r->next=NULL;
	while(r && p)
	{
		t=p->next;
		p->next=r;
		r=p;
		p=t;
	}
	head->next=r;
	L=head;
	return SUCCESS;
}

Status ConnectLinkList(LinkList &La,LinkList Lb)
{
	LNode *p=La;
	while(p->next)
	{
		p=p->next;
	}
	p->next=Lb->next;
	return SUCCESS;
}

Status CirculateLinkList(LinkList &L)
{
	LNode *p=L;
	while(p->next)
	{
		p=p->next;
	}
	p->next=L->next;
	//avoid head node.//
	return SUCCESS;
}

Status TraverseCirculateLinkList(LinkList L,int number)
{
	LNode *p=L->next;int i=1;
	while(p && i<=number)
	{
		cout << p->data << endl;
		p=p->next;
		++i;
	}
	return SUCCESS;
}

Status DblInsertList_H(DblLinkList &L)
{
	int n;cin >> n;
	for(int i=0;i<=n-1;i++)
	{
		DblLNode *t=NULL,*p=new DblLNode;
		cin >> p->data;
		t=L->next;
		L->next=p;
		p->prior=L;
		p->next=t;
		if(t) t->prior=p;
	}
	return SUCCESS;
}

Status TraverseDblLinkList(DblLinkList L,bool senquence)
{
	DblLNode *p=NULL;
	if(senquence)
	{
		p=L->next;
		while(p)
		{
			cout << p->data <<endl;
			p=p->next;
		}
	}
	else
	{
		p=L->next;
		while(p->next)
		{
			p=p->next;
		}
		while(p)
		{
			cout << p->data << endl;
			p=p->prior;
		}
	}
	return SUCCESS;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	DblLNode *L03=NULL;
//	DblInitList(L03);
//	DblInsertList_H(L03);
//	TraverseDblLinkList(L03,0);
	return 0-0;
}


/* Edit on September 11th, 2022. v1.0 */
/* Edit on September 15th, 2022. v1.1 */
