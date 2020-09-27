#include<bits/stdc++.h>
using namespace std;

int fib_rec(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    return fib_rec(n-1)+fib_rec(n-2);
}
int dp[10000]={};
int fib_top_down(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    if(dp[n]!=0)
    {
        return dp[n];
    }
    return dp[n]=fib_top_down(n-1)+fib_top_down(n-2);
}

int dp_bottom_up(int n)
{
    int dps[3]={0};
    int i,j,k;
    for(i=2;i<=n;i++)
    {
        dp[2]=dp[1]+dp[0];
        dp[0]=dp[1];
        dp[1]=dp[2];
    }
    return dp[2];
}

int main()
{
    int i,j,k,n;
    cin>>n;
    dp[0]=0;
    dp[1]=1;
    cout<<dp_bottom_up(n);
}
