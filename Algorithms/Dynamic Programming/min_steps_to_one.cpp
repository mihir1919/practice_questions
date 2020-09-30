#include<bits/stdc++.h>
using namespace std;

int min_2_1(int n,int dp[])
{
    if(n==1)
    {
        return 0;
    }
    if(dp[n]!=0)
    {
        return dp[n];
    }
    int f=(n%3==0?(min_2_1(n/3,dp)):INT_MAX);
    int s=(n%2==0?(min_2_1(n/2,dp)):INT_MAX);
    int t=(n-1>0?(min_2_1(n-1,dp)):INT_MAX);
    return dp[n]=min(f,min(s,t))+1;
}

int m_2_1dp(int n,int dp[])
{
    dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        int f=INT_MAX,s=INT_MAX,t=INT_MAX;
        if(i%3==0)
        {
            f=dp[i/3];
        }
        if(i%2==0)
        {
            s=dp[i/2];
        }
        if(i-1>0)
        {
            t=dp[i-1];
        }
        dp[i]=1+(min(f,min(s,t)));
    }
    return dp[n];
}


int main()
{
    int i,j,k,n;
    cin>>n;
    int dp[n+1]={};
    cout<<min_2_1(n,dp);
}
