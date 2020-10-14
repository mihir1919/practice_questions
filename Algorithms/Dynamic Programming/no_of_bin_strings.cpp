#include<bits/stdc++.h>
using namespace std;

int dp[1000];

int fn(int n,char c)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 2;
    }
    if(dp[n]!=-1)
    {
        return dp[n-1]+dp[n-2];
    }
    if(n==0)
    {
        return 0;
    }
	int yup=0;
	int nope=0;
	if(c!='1')
	{
		yup=fn(n-1,'1');
	}
	nope=fn(n-1,'0');
    //cout<<nope<<" "<<yup<<"\n";
	return dp[n]=yup+nope;
}

int main() {
	int t,i,j,k,n,m;
	cin>>t;
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    dp[1]=2;
    dp[]
	while(t--)
	{
		cin>>n;
		cout<<fn(n,'0')<<endl;
		for(int i=0;i<=n;i++)
		{
			cout<<dp[i]<<" ";
		}
	}
	return 0;
}