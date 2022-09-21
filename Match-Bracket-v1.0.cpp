/*
  Copyright (c) 2022 Qilu University of Technology, Faculty of Computer Science & Technology, Duyu(No.202103180009).
  Source code file of matching bracket. 
  Aug.5, 2022.
 */

#include<bits/stdc++.h>
#include<stack>
using namespace std;
int main(void)
{
	stack<int>s;
	char str[100];scanf("%s",str);
	char *p=str;bool flag=true;
	while(*p && flag)
	{
		switch(*p)
		{
			case '{':
			case '[':
			case '(':
				s.push(*p);
				break;
			case ')':
				if(!s.empty() && s.top()=='(')
				{
					s.pop();
				}
				else flag=false;
				break;
			case ']':
				if(!s.empty() && s.top()=='[')
				{
					s.pop();
				}
				else flag=false;
				break;
			case '}':
				if(!s.empty() && s.top()=='{')
				{
					s.pop();
				}
				else flag=false;
				break;
		}
		++p;
	}
	if(flag) printf("yes");
	else printf("no");
	return 0;
}
