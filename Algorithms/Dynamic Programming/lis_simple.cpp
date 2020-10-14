#include<bits/stdc++.h>
using namespace std;


int dp[1000]={0};


int lis_bottom_up(vector<int> v)
{
    for(int i=0;i<v.size();i++)
    {
        dp[i]=1;
        int m=0;
        for(int j=0;j<i;j++)
        {
            if(v[i]>v[j])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }   
        }
    }
    return *max_element(dp,dp+v.size());
}


// int lis(vector<int> v,int i,int l)
// {
//     if(i==v.size() || v[i]<l)
//     {
//         return 0;
//     }
//     if(dp[i]!=0)
//     {
//         return dp[i];
//     }
//     return dp[i]=max((1+lis(v,i+1,v[i])),(lis(v,i+1,l)));
// }

int main()
{
    int i,j,k,n,m;
    cin>>n;
    vector<int> v(n,0);
    for(i=0;i<n;i++)
    {
        cin>>v[i];
    }
    //cout<<lis(v,0,-1);
    cout<<lis_bottom_up(v);
    cout<<endl;
    for(i=0;i<n;i++)
    {
        cout<<dp[i]<<" ";
    }
}

//8 10 22 9 33 21 50 41 60
//8 1 5 2 3 4 9 6 10