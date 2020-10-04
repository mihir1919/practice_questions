#include<bits/stdc++.h>
using namespace std;

int dp[1000]={0};

int fn(int n)
{
    //cout<<n<<" ";
    if(n<=1)
    {
        return 1;
    }
    if(dp[n]!=0)
    {
        return dp[n];
    }
    for(int i=1;i<=n;i++)
    {
        dp[n]+=fn(n-i)*fn(i);
    }
    return dp[n];
}

int main()
{
    int i,j,k,n,m;
    cin>>n;
    dp[1]=1;
    cout<<fn(n)<<endl;
    for(i=0;i<=n;i++)
    {
        cout<<dp[i]<<" ";
    }
}