#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[1001][1001];

ll fn(vector<ll> si,vector<ll> c,ll s,ll i)
{
	if(i>=si.size())
	{
		return 0;
	}
	if(dp[i][s]!=-1)
	{
		return dp[i][s];
	}
	ll yup=0;
	ll nup=0;
	for(ll j=0;j<si.size();j++)
	{
		if(si[j]<=s)
		{
			yup=max(yup,c[j]+fn(si,c,s-si[j],i+1));
		}
		nup=max(nup,fn(si,c,s,i+1));
	}
	return dp[i][s]=max(yup,nup);
}

ll fn_bm(vector<ll> si,vector<ll> c,ll s)
{
    for(ll i=0;i<si.size();i++)
    {
        dp[i][s]=0;
        for(ll j=0;j<i;j++)
        {
            dp[i][s]=max(dp[i][s],dp[j][s]);
        }
    }
}


int main() {
	ll s,t,i,j,k,n,m;
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>t>>s;
	memset(dp,-1,sizeof(dp));
	vector<ll> si(t,0);
	vector<ll> c(t,0);
	for(i=0;i<t;i++)
	{
		cin>>si[i];
	}
	for(i=0;i<t;i++)
	{
		cin>>c[i];
	}
	cout<<fn(si,c,s,0)<<endl;
	// for(i=0;i<t;i++)
	// {
	// 	cout<<dp[i]<<" ";
	// }
	return 0;
}
