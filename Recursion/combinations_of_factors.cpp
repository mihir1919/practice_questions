#include<bits/stdc++.h>
using namespace std;

void fn(int n,int k,vector<int> v,int f)
{
    if(n==1)
    {
        for(auto x:v)
        {
            cout<<x<<" ";
        }
        cout<<"\n";
       return;
    }
    if(n<1 || k>f/2)
    {
        return;
    }
    if(n%k==0)
    {
        v.push_back(k);
        fn(n/k,k,v,f);
        v.pop_back();
    }
    fn(n,k+1,v,f);
    return;
}
int main()
{
    int i,j,k,n,m,t;
    cin>>n;
    vector<int> v;
    fn(n,2,v,n);
}
