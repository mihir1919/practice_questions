#include<bits/stdc++.h>
using namespace std;

vector<int> coins={1,7,10};

int dp[2002]={0};
int min_coin(int n)
{
    int z=INT_MAX;
    if(n==0)
    {
        return 0;
    }
    if(dp[n]!=0)
    {
        return dp[n];
    }
    for(int i=0;i<coins.size();i++)
    {
        if(coins[i]>n)
        {
            break;
        }
        z=min(1+min_coin(n-coins[i]),z);
    }
    return dp[n]=z;
}

int min_coin_bottom(int n)
{
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        int m=INT_MAX;
        for(int j=0;j<coins.size();j++)
        {
            if(i-coins[j]<0)
            {
                break;
            }
            m=min(m,(dp[i-coins[j]]+1));
        }
        dp[i]=m;
        cout<<m<<" ";
    }
    return dp[n];
}


int main()
{
    int i,j,k,n;
    cin>>n;
    int dp[n+1]={};
    cout<<min_coin_bottom(n);
}

