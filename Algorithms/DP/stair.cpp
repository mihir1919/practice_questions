#include<bits/stdc++.h>
using namespace std;

int dp[100]={0};

int stair(int n,int k)
{
    if(n==0)
    {
        return 1;
    }
    else if(n<0)
    {
        return 0;
    }
    if(dp[n]!=0)
    {
        return dp[n];
    }
    int z=0;
    for(int i=1;i<=k;i++)
    {
        z+=(stair(n-i,k));
    }
    return dp[n]=z;
}

int stair_bm(int n,int k)
{
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j>=i-k;j--)
        {
            dp[i]+=(dp[j]);
        }
    }
    return dp[n];
}

int stair_bm_optimised(int n,int k)
{
    int s=1;
    int z=0;
    deque<int> d;
    d.push_back(1);
    for(int i=1;i<k;i++)
    {
        d.push_back(s);
        s=s*2;
    }
    for(int i=k;i<n;i++)
    {
        if(d.size()>=k)
        {
            //cout<<"beg s "<<s;
            int x=d.front();
            d.pop_front();
            d.push_back(s);
            s-=x;
            s+=(d.back());
            //cout<<" ending s is "<<s<<"\n";
        }
    }
    return s;
}

int main()
{
    int i,j,k,n,m;
    cin>>n>>k;
    cout<<stair_bm_optimised(n,k);
}
