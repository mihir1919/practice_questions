#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[2001][2001][6];

ll fn(vector<ll> v,vector<ll> w,ll x,ll i,ll j)
{
	if(i==v.size() || j==w.size())
	{
		return 0;
	}
	if(dp[i][j][x]!=-1)
	{
		return dp[i][j][x];
	}
	ll a=0,b=0,c=0;
	if(v[i]==w[j])
	{
		a=1+fn(v,w,x,i+1,j+1);
		b=fn(v,w,x,i,j+1);
		c=fn(v,w,x,i+1,j);	
	}
	else
	{
		if(x>0)
		{
			int temp=v[i];
			v[i]=w[j];
			a=1+fn(v,w,x-1,i+1,j+1);
			v[i]=temp;
		}
		b=fn(v,w,x,i,j+1);
		c=fn(v,w,x,i+1,j);
	}
	return dp[i][j][x]=max(a,max(b,c));
}

int main() 
{
	ll i,j,k,n,m,x;
	cin>>n>>m>>x;
	vector<ll> v(n,0);
	vector<ll> w(m,0);
	memset(dp,-1,sizeof(dp));
	for(i=0;i<n;i++)
	{
		cin>>v[i];
	}
	for(i=0;i<m;i++)
	{
		cin>>w[i];
	}
	cout<<fn(v,w,x,0,0);
	return 0;
}