#include<bits/stdc++.h>
using namespace std;


vector<int> dp(1000,0);

int lis_opt(vector<int> v)
{
    dp[0]=INT_MIN;
    for(int i=1;i<=v.size();i++)
    {
        dp[i]=INT_MAX;
    }
    for(int i=0;i<v.size();i++)
    {
        int j=upper_bound(dp.begin(),dp.begin()+v.size(),v[i])-dp.begin();
            if(dp[j-1]<v[i] && dp[j]>v[i])
            {
                dp[j]=v[i];
            }
    }
    int k=0;
    for(int i=1;i<v.size();i++)
    {
        if(dp[i]!=INT_MAX)
        {
            k++;
        }
    }
    return k;
}

int lis(vector<int> v)
{
    dp[0]=INT_MIN;
    for(int i=1;i<=v.size();i++)
    {
        dp[i]=INT_MAX;
    }
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if(dp[j]<v[i] && dp[j+1]>v[i])
            {
                dp[j+1]=v[i];
            }
        }
    }
    int k=0;
    for(int i=1;i<v.size();i++)
    {
        if(dp[i]!=INT_MAX)
        {
            k++;
        }
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
    //cout<<lis(v,0,-1);
    cout<<lis_opt(v);
    cout<<endl;
    for(i=0;i<n;i++)
    {
        cout<<dp[i]<<" ";
    }
}

//8 10 22 9 33 21 50 41 60
//8 1 5 2 3 4 9 6 10