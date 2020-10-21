#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];
int fn(vector<int> v,int i,int j)
{
    if(i>j)
    {
        return 0;
    }
    if(dp[i][j]!=0)
    {
        return dp[i][j];
    }
    dp[i][j]=max(v[i]+min(fn(v,i+1,j-1),fn(v,i+2,j)),v[j]+min(fn(v,i+1,j-1),fn(v,i,j-2)));
    return dp[i][j];
}

int main()
{
    int i,j,k,n,m;
    cin>>n;
    memset(dp,0,sizeof(dp));
    vector<int> v(n,0);
    for(i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<fn(v,0,n-1)<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}