#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int n,m,k,x,y;
int fn(vector<vector<int>> w,int i,int j)
{
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(i>=n || j>=m)
    {
        return dp[i][j]=0;
    }
    if(w[i][j]==-1)
    {
        return dp[i][j]=0;
    }
    if(i==n-1 && j==m-1)
    {
        return dp[i][j]=1;
    }
    return dp[i][j]=fn(w,i+1,j)+fn(w,i,j+1);
}


int fn_bm(vector<vector<int>> w)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dp[i][j]==-1)
            {
                return
            }
            dp[i][j]+=(i==0 && j==0)?w[0][0]:0;
            dp[i][j]+=i==0?dp[i-1][j]:0;
            dp[i][j]+=j==0?dp[i][j-1]:0;
        }
    }

}

int main()
{
    int i,j;
    cin>>n>>m>>k;
    vector<vector<int>> w;
    for(int i=0;i<=n;i++)
    {
        vector<int> v(m+1,0);
        vector<int> t(m+1,-1);
        dp.push_back(t);
        w.push_back(v);
    }
    for(int i=0;i<k;i++)
    {
        cin>>x>>y;
        w[x-1][y-1]=-1;
    }
    cout<<fn(w,0,0)<<"\n";
    
}