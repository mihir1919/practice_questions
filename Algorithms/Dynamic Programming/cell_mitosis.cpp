#include<bits/stdc++.h>
using namespace std;


int dp[1000]={0};


int cell(int n,int x,int y,int z)
{
    for(int i=2;i<=n;i++)
    {
        if(i%2==0)
        {
            dp[i]=min(dp[i/2]+x,dp[i-1]+y);
        }
        else
        {
            dp[i]=min((dp[(i+1)/2]+x+z),dp[i-1]+y);
        }
    }
    return dp[n];
}

int cell_td(int m,int n,int x,int y,int z)
{
    dp[0]=0;
    dp[1]=0;
    if(n==m)
    {
        return 0;
    }
    if(m>n+1 || m<=0)
    {
        return INT_MAX;
    }
    if(dp[m]!=0)
    {
        return dp[m];
    }
    int db=x+cell_td(m*2,n,x,y,z);
    int l=y+cell_td(m+1,n,x,y,z);
    int mo=z+cell_td(m-1,n,x,y,z);
    cout<<db<<" "<<l<<" "<<mo<<" "<<m<<"\n";
    return dp[m]=min(db,(min(l,mo)));
}

int main()
{
    int i,j,k,n,m,z,y,x;
    cin>>n>>x>>y>>z;
    cout<<cell_td(1,n,x,y,z);
    cout<<endl;
    for(int i=0;i<=n;i++)
    {
        cout<<dp[i]<<" ";
    }
}

//8 10 22 9 33 21 50 41 60
//8 1 5 2 3 4 9 6 10