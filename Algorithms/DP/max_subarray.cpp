#include<bits/stdc++.h>
using namespace std;

int max_sub(vector<int> v)
{
    int i,j,k;
    int dp[2];
    dp[0]=0;
    k=INT_MIN;
    for(i=1;i<=v.size();i++)
    {
        dp[1]=(dp[0]+v[i-1]<v[i-1]?v[i-1]:v[i-1]+dp[0]);
        k=max(k,dp[1]);
        dp[0]=dp[1];
    }
    return k;
}

int main()
{
    int i,j,k,n,m;
    cin>>n;
    vector<int> v(n,0);
    for(i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<max_sub(v);
}
//8 -2 -3 -4 -1 -2 -1 -5 -3
