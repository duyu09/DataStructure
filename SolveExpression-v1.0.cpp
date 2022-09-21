/*
  Copyright (c) 2022 Qilu University of Technology, Faculty of Computer Science & Technology, Duyu(No.202103180009).
  Source code file of expression soluting. 
  Sept.19~21, 2022.
*/

#include <bits/stdc++.h>
#define MAX_ARRSIZE 100
#define ERR_OVERFLOW -255
#define ERR_ERROR 9
#define SUCCESS 255
#define MAX_SIZE 50

using namespace std;
typedef int Status;
typedef double ElemType;
typedef char ElemTypeTR;
typedef struct StackMeta
{
	ElemType *top;
	ElemType *base;
	int StackSize;
}Stack;

typedef struct StackTRMeta
{
	ElemTypeTR *top;
	ElemTypeTR *base;
	int StackSize;
}StackTR;

typedef struct StackData
{
	double number;
	char opera;
	bool flag;
}SData;

SData* Split(char *str,int *n)
{
	SData *arr=new SData[MAX_ARRSIZE];
	char *p=str,*r=p;int ind=0;
	while(*p)
	{
		if(isdigit(*p)||*p=='.')
		{
			r=p;
			while(isdigit(*r)||*r=='.') ++r;
			char v[100];
			memcpy(v,p,(r-p)*sizeof(char));
			v[r-p]=0;
			double temp=atof(v);
			p=r;
			arr[ind].number=temp;
			arr[ind].flag=1;
			++ind;
		}
		else
		{
			if(*p=='+'||*p=='-'||*p=='*'||*p=='/'||*p=='('||*p==')'||*p=='#')
			{
				arr[ind].opera=*p;
				arr[ind].flag=0;
				++ind;
			}
			++p;
		}
	}
	*n=ind;
	return arr;
}

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

ElemType GetTop(Stack S)
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

Status ClearStack(Stack &S)
{
	S.top=S.base;
	return SUCCESS;
}

Status InitStackTR(StackTR &S)
{
	ElemTypeTR *p=new ElemTypeTR[MAX_SIZE];
	if(!p) return ERR_OVERFLOW;
	S.base=p;
	S.top=S.base;
	S.StackSize=MAX_SIZE;
	return SUCCESS;
}

Status PushTR(StackTR &S,ElemTypeTR e)
{
	if(S.top-S.base==S.StackSize) return ERR_ERROR;
	++S.top;
	*(S.top)=e;
	return SUCCESS;
}

ElemTypeTR PopTR(StackTR &S)
{
	if(S.base==S.top) return ERR_ERROR;
	ElemTypeTR temp=*(S.top);
	--S.top;
	return temp;
}

ElemTypeTR GetTopTR(StackTR S)
{
	return *(S.top);
}

Status TraverseStackTR(StackTR S)
{
	ElemTypeTR *p=S.top;
	while(p!=S.base)
	{
		cout << *p << endl;
		--p;
	}
	return SUCCESS;
}

int StackLengthTR(StackTR S)
{
	int count=0;ElemTypeTR *p=S.top;
	while(p!=S.base)
	{
		++count;
		--p;
	}
	return count;
}

bool isStackEmptyTR(StackTR S)
{
	return S.top==S.base;
}

Status ClearStackTR(StackTR &S)
{
	S.top=S.base;
	return SUCCESS;
}

int CompareLevel(char op1,char op2)
{
	int n=0;
	switch (op1)
	{
	case '+':
	case '-':
		if(op2=='+') n=1;
		if(op2=='-') n=1;
		if(op2=='*') n=-1;
		if(op2=='/') n=-1;
		if(op2=='(') n=-1;
		if(op2==')') n=1;
		if(op2=='#') n=1;
		break;
	case '*':
	case '/':
		if(op2=='+') n=1;
		if(op2=='-') n=1;
		if(op2=='*') n=1;
		if(op2=='/') n=1;
		if(op2=='(') n=-1;
		if(op2==')') n=1;
		if(op2=='#') n=1;
		break;
	case '(':
		if(op2==')') n=0;
		else n=-1;
		break;
	case ')':
		n=1;
		break;
	case '#':
		if(op2=='#') n=0;
		else n=-1;
		break;
	}
	return n;
}

double Calculate(double num01,double num02,char opera)
{
	double temp=0;
	switch(opera) 
	{
	case '+':
		temp=num01+num02;
		break;
	case '-':
		temp=num01-num02;
		break;
	case '*':
		temp=num01*num02;
		break;
	case '/':
		temp=num01/num02;
		break;
	default:
		temp=(double)ERR_ERROR;
		break;
	}
	return temp;
}

Status StringInsert(char *str,char ch,int index)
{
	int a=strlen(str);
	for(int i=a-1;i>=index;--i)
	{
		str[i+1]=str[i];
	}
	str[a+1]=0;
	str[index]=ch;
	return SUCCESS;
}

Status ZeroInsert(char *str)
{
	if(str[0]=='-') StringInsert(str,'0',0);
	char *p=str;
	while(*p)
	{
		if(*p=='(' && *(p+1)=='-')
		{
			StringInsert(str,'0',p-str+1);
		}
		++p;
	}
	return SUCCESS;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	Stack OPND;StackTR OPTR;
	InitStack(OPND);
	InitStackTR(OPTR);
	PushTR(OPTR,'#');
	char str[MAX_ARRSIZE];cin >> str;
	ZeroInsert(str);
	strcat(str,"########");
	int n;
	SData *p=Split(str,&n);
	for(int i=0;i<=n-1;++i)
	{
		if(p[i].flag) Push(OPND,p[i].number);
		else
		{
			char op=p[i].opera;
			switch(CompareLevel(GetTopTR(OPTR),op))
			{
			case -1:
				PushTR(OPTR,op);
				break;
			case 1:
				{
				char optemp=PopTR(OPTR);
				if(op!=')')PushTR(OPTR,op);
				double a=Pop(OPND),b=Pop(OPND);
				Push(OPND,Calculate(b,a,optemp));
				break;
				}
			case 0:
				PopTR(OPTR);
				break;
			}
		}
	}
	cout << GetTop(OPND);
	return 0 - 0;
}

/*
  End of source code of SolveEquition.cpp.
 */

