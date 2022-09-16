// Copyright (c) 2022 Qilu University of Technology, Faculty of Computer Science & Technology, Duyu.(No.202103180009).
#include<bits/stdc++.h>
using namespace std;
long long count01=0;
void Hanoi(int n,char a,char b,char c)
{
	if(n==1)
	{
		++count01;
		printf("%d: %d %c %c\n",count01,1,a,c);
	}
	else
	{
		Hanoi(n-1,a,c,b);
		++count01;
		printf("%d: %d %c %c\n",count01,n,a,c);
		Hanoi(n-1,b,a,c);
	}
}
int main()
{
	Hanoi(20,'a','b','c');
	return 0;
}
