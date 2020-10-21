#include<bits/stdc++.h>
using namespace std;

int dp[1000]={0};

int fn(int n)
{
    if(dp[n]!=0)
    {
        return dp[n];
    }
    if(n>2)
    {
        return dp[n]=fn(n-1)+(n-1)*fn(n-2);
    }
    else
    {
        return dp[n]=n;
    }
    return 0;
    
}

int main()
{
    int i,j,k,n,m;
    cin>>n;
    dp[1]=1;
    //memset(dp,0,sizeof(dp));
    //vector<int> v(n,0);
    cout<<fn(n)<<endl;
    for(i=0;i<=n;i++)
    {
        cout<<dp[i]<<" ";
    }
}