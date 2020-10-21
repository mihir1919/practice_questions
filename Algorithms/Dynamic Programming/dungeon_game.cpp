#include<bits/stdc++.h>
using namespace std; 
int dp[10000][10000];
    
    int dpzz(vector<vector<int>> d,int i,int j)
    {
        if(i==d.size()-1 && j==d[0].size()-1)
        {
            return 0;
        }
        if(i>=d.size() || j>=d[0].size())
        {
            return INT_MIN;
        }
        if(dp[i][j]!=INT_MIN)
        {
            return dp[i][j];
        }
        if(i==d.size()-1 && ((j<=d[0].size()-1)&&(j>=0)))
        {
            dp[i][j]=abs(d[i][j])-d[i][j]+dpzz(d,i,j+1);
        }
        else if(j==d[0].size()-1 && ((i<=d.size()-1)&&(i>=0)))
        {
            dp[i][j]=abs(d[i][j])-d[i][j]+dpzz(d,i+1,j);
        }
        else
        {
            dp[i][j]=abs(d[i][j])-max(dpzz(d,i+1,j),dpzz(d,i,j+1));
        }
        return dp[i][j];
    }
    int calculateMinimumHP(vector<vector<int>> d) {  
        for(int i=0;i<d.size();i++)
        {
            for(int j=0;j<d[0].size();j++)
            {
                dp[i][j]=INT_MIN;
            }
        }
        return dpzz(d,0,0);
    }

int main()
{
    vector<vector<int>> v;
    int n,m,k;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        vector<int> w;
        for(int j=0;j<m;j++)
        {
            cin>>k;
            w.push_back(k);
        }
        cout<<"ss "<<endl;
        v.push_back(w);
    }
    calculateMinimumHP(v);
}