#include<bits/stdc++.h>
using namespace std;



bool par(string s)
{
	int i;
	stack<char> c;
	for(i=0;i<s.length();i++)
	{
		if(s[i]!=')')
		{
			c.push(s[i]);
		}
		else
		{
			if(c.top()=='(')
			{
				return false;
			}
			else
			{
				while(!c.empty() && c.top()!='(')
				{
					c.pop();
				}
				if(!c.empty() && c.top()=='(')
				{
					c.pop();
				}
			}
		}
	}
	return true;
}

int main()
{
	int i,j,k,n,m;
	cin>>n;
	string s;
	for(i=0;i<n;i++)
	{
		cin>>s;
		cout<<(par(s)==1?"Not Duplicates\n":"Duplicate\n");
	}
	return 0;
}
