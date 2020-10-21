#include<bits/stdc++.h>
using namespace std;

string dp[1000][1000];

string fn(string s,string t,int i,int j)
{
	if(dp[i][j]!="-1")
	{
		return dp[i][j];
	}
	if(i==s.length() || j==t.length())
	{
		return dp[i][j]="";
	}
	if(s[i]==t[j])
	{
		return dp[i][j]=s[i]+fn(s,t,i+1,j+1);
	}
	else
	{
		string si=fn(s,t,i,j+1);
        string sj=fn(s,t,i+1,j);
        if(si.length()>sj.length())
        {
            return dp[i][j]=si;
        }
        else
        {
            return dp[i][j]=sj;
        }
        
	}
    //dp[i][j]=ans.length();
	return "";
}

string fn_bm(string s,string t)
{
    for(int i=1;i<=s.length();i++)
    {
        for(int j=1;j<=t.length();j++)
        {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+s[i-1];
                }
                else if(dp[i-1][j].length()>dp[i][j-1].length())
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i][j-1];
                }
        }
    }
    return dp[s.length()][t.length()];
}

int main() 
{
	int i,j,k,m,n;
	string s,t;
	cin>>s>>t;
    for(int i=0;i<s.length()+1;i++)
    {
        for(int j=0;j<t.length()+1;j++)
        {
            dp[i][j]="";
        }
    }
	//cout<<fn(s,t,0,0);
	cout<<fn_bm(s,t)<<endl;
    return 0;
}