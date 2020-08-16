#include<bits/stdc++.h>
using namespace std;

bool isprime(int k)
{
	for(int i=2;i<=sqrt(k);i++)
	{
		if(k%i==0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	stack<int> s;
	int i,j,k,n,m;
	vector<stack<int>> v;
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>m;
		s.push(m);
	}
	int arr[k];
	int h=1;
	for(int j=0;j<k;j++)
	{
	    h++;
		while(!isprime(h))
		{
			h++;
		}
		arr[j]=h;
	}
    cout<<"\n";
	v.push_back(s);
	int t=1;
	while(k--)
	{
		int g=arr[t-1];
		stack<int> tempa;
		stack<int> tempb;
		while(!v[0].empty())
		{
			int y=v[0].top();
			if(y%g==0)
			{
				tempb.push(y);
			}
			else
			{
				tempa.push(y);
			}
			v[0].pop();
		}
		v.push_back(tempb);
		swap(tempa,v[0]);
	}
	for(int r=1;r<v.size();r++)
	{
		while(!v[r].empty())
		{
			cout<<v[r].top()<<"\n";
			v[r].pop();
		}
	}
	while(!v[0].empty())
    {
        cout<<v[0].top()<<"\n";
        v[0].pop();
    }
	return 0;
}
