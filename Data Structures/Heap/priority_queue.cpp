#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int,vector<int>,greater<int>> pq;
    int i,j,k,n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        pq.push(k);
    }
    for(auto x:pq)
    {
        cout<<x<<" ";
    }
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
==
