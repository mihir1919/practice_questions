#include<bits/stdc++.h>
#define ll long long
#define sort(v) sort(v.begin(),v.end())
using namespace std;
int main()
{
    ll i,j,k,n,m;
    cin>>n>>m;
    vector<ll> v(n,0);
    for(i=0;i<n;i++)
    {
        cin>>k;
        v[i]=k;
    }
    sort(v);
    i=0;
    ll c=0;
    while(i<v.size())
    {
        //cout<<i<<" ";
        j=upper_bound(v.begin(),v.end(),v[i]+m)-v.begin();
        if(j>=v.size())
        {
            c+=(v.size()-i)/2;
            break;
        }
        //cout<<j<<"\n";
        c+=(j-i)/2;
        if((j-i)%2==0)
        {
            i=j;
        }
        else if((j-i)==1)
        {
            i=j;
        }
        else
        {
            i=j-1;
        }
    }
    cout<<c;
}
//5 0
//1
//3
//3
//9
//4
