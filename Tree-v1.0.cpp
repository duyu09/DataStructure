/*
  Copyright (c) 2022 QILU UNIVERSITY OF TECHNOLOGY,
  FACULTY OF COMPUTER SCIENCE AND TECHNOLOGY,
  DUYU.(NO.202103180009).
  
  CPP Source code file of Tree.
  October 19th, 2022.
 */

#include<bits/stdc++.h>
#define SUCCESS 0
#define ERR_ERROR 1
#define ERR_OVERFLOW -1
#define MAX_INTEGER 32765
using namespace std;
typedef int Status;
typedef int ElemType;
typedef struct TNode
{
	TNode* rchild;
	TNode* lchild;
	ElemType data;
}TNode,*BiTree;

Status InitTree(BiTree &T)
{
	T=NULL;
	return SUCCESS;
}

Status CreateTree(BiTree &T)
{
	ElemType d;
	cin >> d;
	if(d==-1)
	{
		T=NULL;
		return SUCCESS;
	}
	T=new TNode;
	T->data=d;
	printf("Please Input Left Node:\n");
	CreateTree(T->lchild);
	printf("Please Input Right Node:\n");
	CreateTree(T->rchild);
	return SUCCESS;
}

Status TransferTree_H(BiTree T)
{
	if(T)
	{
		cout << T->data << endl;
		TransferTree_H(T->rchild);
		TransferTree_H(T->lchild);
	}
	return SUCCESS;
}

Status TransferTree_M(BiTree T)
{
	if(T)
	{
		TransferTree_H(T->rchild);
		cout << T->data << endl;
		TransferTree_H(T->lchild);
	}
	return SUCCESS;
}

Status TransferTree_B(BiTree T)
{
	if(T)
	{
		TransferTree_B(T->rchild);
		TransferTree_B(T->lchild);
		cout << T->data << endl;
	}
	return SUCCESS;
}

int GetDepth(BiTree T)
{
	if(T)
	{
		int a=GetDepth(T->rchild);
		int b=GetDepth(T->lchild);
		return max(a,b)+1;
	}
	else return 0;
}

int GetNodeNum(BiTree T)
{
	if(T)
	{
		int a=GetNodeNum(T->rchild);
		int b=GetNodeNum(T->lchild);
		return a+b+1;
	}
	else return 0;
}

int GetMax(BiTree T)
{
	if(T)
	{
		int a=GetMax(T->rchild);
		int b=GetMax(T->lchild);
		int c=T->data;
		return max(max(a,b),c);
	}
	return -MAX_INTEGER;
}

int main(void)
{
	BiTree T;
	InitTree(T);
	CreateTree(T);
	cout << "Preorder Traversal" << endl;
	TransferTree_H(T);
	cout << "Inorder Traversal" << endl;
	TransferTree_M(T);
	cout << "Postorder Traversal" << endl;
	TransferTree_B(T);
	cout << "Depth of Tree" << endl;
	cout << GetDepth(T);
	return 0-0;
}

/*
  End of Source Code of Tree.
 */
