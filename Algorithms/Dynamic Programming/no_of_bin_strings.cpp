#include<bits/stdc++.h>
using namespace std;

int dp[1000]={-1};

int fn(int n,char c)
{
	if(n==0)
	{
		return 1;
	}
	if(dp[n]!=-1)
	{
		return dp[n];
	}
	int yup=0;
	int nope=0;
	if(c!='1')
	{
		yup=fn(n-1,'1');
	}
	nope=fn(n-1,'0');
	return dp[n]=yup+nope;
}

int main() {
	int t,i,j,k,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<fn(n,'0')<<endl;
		for(int i=0;i<=n;i++)
		{
			return dp[i];
		}
	}
	return 0;
}