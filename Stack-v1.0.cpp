//Copyright (c) 2022 Qilu University of Technology, Faculty of Computer Science & Technology, Duyu (No.202103180009).
#include<bits/stdc++.h>
#define ERR_OVERFLOW -1
#define ERR_ERROR -2
#define SUCCESS 0
#define MAX_SIZE 5
using namespace std;
typedef int Status;
typedef double ElemType;
typedef struct SMeta
{
	ElemType *top;
	ElemType *base;
	int StackSize;
}Stack;

Status InitStack(Stack &S)
{
	ElemType *p=new ElemType[MAX_SIZE];
	if(!p) return ERR_OVERFLOW;
	S.base=p;
	S.top=S.base;
	S.StackSize=MAX_SIZE;
	return SUCCESS;
}

Status Push(Stack &S,ElemType e)
{
	if(S.top-S.base==S.StackSize) return ERR_ERROR;
	++S.top;
	*(S.top)=e;
	return SUCCESS;
}

ElemType Pop(Stack &S)
{
	if(S.base==S.top) return ERR_ERROR;
	ElemType temp=*(S.top);
	--S.top;
	return temp;
}

Status GetTop(Stack S)
{
	return *(S.top);
}

Status TraverseStack(Stack S)
{
	ElemType *p=S.top;
	while(p!=S.base)
	{
		cout << *p << endl;
		--p;
	}
	return SUCCESS;
}

int StackLength(Stack S)
{
	int count=0;ElemType *p=S.top;
	while(p!=S.base)
	{
		++count;
		--p;
	}
	return count;
}

bool isStackEmpty(Stack S)
{
	return S.top==S.base;
}

Status DestroyStack(Stack &S)
{
	delete[] S.base;
	return SUCCESS;
}

Status ClearStack(Stack &S)
{
	S.top=S.base;
	return SUCCESS;
}

int main(int argc,char **argv)
{
	Stack S;
	InitStack(S);
	// Demo.
	return 0;
}

