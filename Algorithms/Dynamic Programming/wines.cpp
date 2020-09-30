#include<bits/stdc++.h>
using namespace std;

int dp[100][100];


int wine(vector<int> v,int l,int r,int i)
{
    if(l>r)
    {
        return 0;
    }
    if(dp[l][r]!=0)
    {
        return dp[l][r];
    }
    return dp[l][r]=max((v[l]*(i))+wine(v,l+1,r,i+1),(v[r]*(i))+wine(v,l,r-1,i+1));
}

int wine_bm(vector<int> v)
{
    int i,j;
    for(i=0;i<v.size();i++)
    {
        dp[i][i]=(v.size())*(v[i]);
        cout<<dp[i][i]<<" ";
    }
    cout<<endl;
    int t=v.size()-1;
    while(t--)
    {
        i=0,j=v.size()-t-1;
        while(i<v.size() && j<v.size())
        {
            cout<<i<<" "<<j<<" are i and j "<<dp[i][j-1]<<" "<<dp[i+1][j]<<endl;
            dp[i][j]=dp[i][j-1]+dp[i+1][j];
            i++;
            j++;
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return dp[0][v.size()-1];
}

int main()
{
    int i,j,k,n,m,t;
    cin>>n;
    vector<int> v(n,0);
    for(i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            dp[i][j]=0;
        }
    }
    cout<<wine_bm(v);
}
//5 2 3 5 1 4
