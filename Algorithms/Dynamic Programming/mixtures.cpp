#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int fn(vector<int> v)
{
    if(do=)
    for(int i=0;i<v.size();i++)
    {
        for(int k=0;k<i;k++)
        {
            dp[i][]=min(dp[i][k] + dp[k+1][v.size()])
        }
    }
    return 0;
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
    cout<<fn(v);
}