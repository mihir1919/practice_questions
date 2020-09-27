#include<bits/stdc++.h>
using namespace std;

int load_b(vector<int> v)
{
    int r=0,l=0,i,k=0,n=v.size();
    for(i=0;i<v.size();i++)
    {
        r+=v[i];
    }
    k=r/v.size();
    if(r%v.size()!=0)
    {
        return -1;
    }
    int m=0;
    for(i=0;i<v.size();i++)
    {
        r-=v[i];
        l+=v[i];
        m=max(max(abs(((i+1)*k)-l),abs(((n-1-i)*k)-r)),m);
    }
    return m;
}

int main()
{
    int i,j,k,n,m;
    cin>>n;
    vector<int> arr(n,0);
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<load_b(arr);
}
