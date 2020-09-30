#include<bits/stdc++.h>
using namespace std;

int dp[1000]={0};

int rod(vector<int> v,vector<int> p,int n)
{
    int z=0;
    if(n==0)
    {
        return 0;
    }
    if(n<0)
    {
        return INT_MIN;
    }
    if(dp[n]!=0)
    {
        return dp[n];
    }
    for(int i=0;i<v.size();i++)
    {
        if((n-v[i])>=0)
        {
            z=max(z,p[i]+rod(v,p,n-v[i]));
        }
        else
        {
            break;
        }
    }
    return dp[n]=z;
}


int r_b(vector<int> v,vector<int> p,int n)
{
    int z=0;
    dp[0]=0;
    dp[1]=p[0];
    for(int i=2;i<=v.size();i++)
    {
        int m=0;
        for(int j=i;j>=0;j--)
        {
            m=max(p[j-1]+dp[abs(i-j-1)],m);
        }
        dp[i]=m;
        //cout<<dp[i]<<" ";
    }
    return dp[v.size()];
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n,0);
    vector<int> p(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    cout<<rod(v,p,n);
}

//8
//1 2 3 4 5 6 7 8
//3 5 8 9 10 17 17 20
