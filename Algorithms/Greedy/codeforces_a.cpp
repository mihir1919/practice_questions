#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool isnull(vector<int> v)
{
    if(*max_element(v.begin(),v.end())==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    ll i,j,k,n,m,t;
    cin>>n;
    deque<ll> hand(n,0);
    vector<ll> pile(n,0);
    for(i=0;i<n;i++)
    {
        cin>>k;
        hand[i]=k;
    }
    for(i=0;i<n;i++)
    {
        cin>>k;
        pile[i]=k;
    }
    while(!isnull(pile))
    {
        if()
    }

}
