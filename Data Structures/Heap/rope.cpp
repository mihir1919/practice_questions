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
    int s=0;
    int x=0;
    while(pq.size()>1)
    {
        cout<<pq.top()<<" ";
        x+=pq.top();
        pq.pop();
        if(!pq.empty())
        {
            cout<<pq.top()<<" ";
            x+=pq.top();
            pq.pop();
        }
        pq.push(x);
        s+=x;
        x=0;
    }
    cout<<s<<" ";
}
//4 4 3 2 6

