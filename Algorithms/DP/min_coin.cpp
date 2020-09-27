#include<bits/stdc++.h>
using namespace std;

vector<int> coins={1,2,5,10,20,50,100,200,500,1000,2000};

int dp[coins.size()][2001]={0};
int min_coin(int n)
{
    for(int i=0;i<coins.size();i++)
    {
        if(dp[i][n]!=0)
        {
            return dp[i][n];
        }
    }
    return min()
}


int main()
{
    int i,j,k,n;
    cin>>n;
    int dp[n+1]={};
    cout<<min_coin(n,dp);
}

