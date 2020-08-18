#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,k,m,n;
	cin>>n;
	deque<int> q1;
	deque<int> q2;
	for(i=0;i<n;i++)
	{
		cin>>m;
		q1.push_back(m);
	}
	int coun=0;
	for(i=0;i<n;i++)
	{
		cin>>m;
		if(q1.front()==m)
		{
			q1.pop_front();
		}
		else
		{
			while(!q1.empty() && q1.front()!=m)
			{
				int x=q1.front();
				q1.pop_front();
				q1.push_back(x);
				coun++;
			}
			q1.pop_front();
		}
		coun++;
		cout<<coun<<" ";
	}
	cout<<coun<<"\n";
	return 0;
}
