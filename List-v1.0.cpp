/* 
  Copyright (c) 2022 Qilu University of Technology, 
  Faculty of Computer Science & Technology, 
  Duyu.(No.202103180009).
  
  Source Code File of LinkList. v1.1
*/

#include<bits/stdc++.h>
#define ERR_OVERFLOW -1
#define ERR_ERROR -2
#define SUCCESS 0
#define MIN_NUMBER 1000000
#define ARR_SIZE 100
using namespace std;
typedef int Status;
typedef int ElemType;
typedef struct List
{
	ElemType *base;
	int size;
}List;

Status InitList(List &L)
{
	L.base=new ElemType[ARR_SIZE];
	L.size=0;
	return SUCCESS;
}

Status CreateList(List &L,int n)
{
	L.size=n;
	ElemType *p=L.base;
	for(int i=0;i<=n-1;++i)
	{
		cin >> p[i];
	}
	return SUCCESS;
}

ElemType GetElem(List L,int index)
{
	if(index>L.size-1 || index<0) return ERR_ERROR;
	else return L.base[index-1];
}

Status TraverseList(List L)
{
	for(int i=0;i<=L.size-1;++i)
	{
		cout << L.base[i] << endl;
	}
	return SUCCESS;
}

Status InsertElem(List &L,int index,ElemType e)
{
	ElemType *p=L.base;
	if(index>L.size) return ERR_ERROR;
	else
	{
		for(int i=L.size-1;i>=index;--i)
		{
			p[i+1]=p[i];
		}
		p[index]=e;
	}
	++L.size;
	return SUCCESS;
}

Status DeleteElem(List &L,int index)
{
	if(index>L.size-1) return ERR_ERROR;
	else
	{
		ElemType *p=L.base;
		for(int i=index+1;i<=L.size-1;++i)
		{
			p[i-1]=p[i];
		}
	}
	--L.size;
	return SUCCESS;
}

int FindElem(List L,ElemType e)
{
	ElemType *p=L.base;
	for(int i=0;i<=L.size-1;++i)
	{
		if(p[i]==e) return i;
	}
	return ERR_ERROR;
}

Status ReverseList(List &L)
{
	ElemType *p=L.base;
	for(int i=0;i<=L.size/2-1;++i)
	{
		ElemType temp=p[i];
		p[i]=p[L.size-1-i];
		p[L.size-1-i]=temp;
	}
	return SUCCESS;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	List L;
	InitList(L);
	CreateList(L,4);
	InsertElem(L,3,100);
	ReverseList(L);
	TraverseList(L);
	return 0-0;
}

/*
  Edit on October 1st, 2022. v1.0
  Edit on October 2nd, 2022. v1.1 
*/
