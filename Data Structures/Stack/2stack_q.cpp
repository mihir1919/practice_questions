#include<bits/stdc++.h>
using namespace std;

class q{

	stack<int> s1;
	stack<int> s2;
	public:
		void pushq(int data)
		{
			if(s1.empty())
			{
				s1.push(data);
			}
			else
			{
				while(!s1.empty())
				{
					int x=s1.top();
					s1.pop();
					s2.push(x);
				}
				s1.push(data);
				while(!s2.empty())
				{
					int x=s2.top();
					s2.pop();
					s1.push(x);
				}
			}
		}

		void popq()
		{
			if(!s1.empty())
			{
				while(!s1.empty())
				{
					int x=s1.top();
					s1.pop();
					if(s1.empty())
					{
						break;
					}
					s2.push(x);
				}
				while(!s2.empty())
				{
					int x=s2.top();
					s2.pop();
					s1.push(x);
				}
			}
		}

		void prn()
		{
			while(!s1.empty())
				{
					int x=s1.top();
					s1.pop();
					cout<<x<<" ";
				}
		}
};

int main()
{
	int n;
	cin>>n;
	q qu;
	for(int i=0;i<n;i++)
	{
		qu.pushq(i);
	}
	qu.prn();
	return 0;
}
