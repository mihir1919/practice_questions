#include<bits/stdc++.h>
using namespace std;

void comb(vector<int> v,int i,int n,vector<int> ans)
{
    if(ans.size()==n)
    {
        for(auto x:ans)
        {
            cout<<x<<" ";
        }
        cout<<"\n";
        return;
    }
    else if(i>v.size()-n+1)
    {
        return;
    }

    if(ans.size()<n)
    {
        ans.push_back(v[i]);
        comb(v,i+1,n,ans);
        ans.pop_back();
    }
    comb(v,i+1,n,ans);
}

int main()
{
    int i,j,k,n,m;
    vector<int> v={1,2,3,4};
    cin>>n;
    i=0;
    vector<int> ans;
    comb(v,i,n,ans);
}
