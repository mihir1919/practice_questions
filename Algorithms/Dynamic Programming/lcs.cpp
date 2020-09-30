#include<bits/stdc++.h>
using namespace std;


int dp[100][100];

int lcs(string s,string t,int i,int j)
{
    int z=0;
    if(s.length()==i || t.length()==j)
    {
        return 0;
    }
    if(dp[i][j]!=0)
    {
        return dp[i][j];
    }
    if(s[i]==s[j])
    {
        z+=1+lcs(s,t,i+1,j+1);
    }
    else
    {
        z+=max(lcs(s,t,i+1,j),lcs(s,t,i,j+1));
    }
    return dp[i][j]=z;
}

int main()
{
    int i,j,k,n;
    string s,t;
    cin>>s>>t;
    for(i=0;i<100;i++)
    {
        for(j=0;j<100;j++)
        {
            dp[i][j]=0;
        }
    }
    cout<<lcs(s,t,0,0);
}