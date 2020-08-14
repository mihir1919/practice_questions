#include<bits/stdc++.h>
using namespace std;

void stock(vector<int> v,vector<int> &span)
{
    stack<pair<int,int>> s;
    int i,j,k=0;
    i=0,j=0;
    while(i<v.size())
    {
        k=0,j=0;
        while(!s.empty() && s.top().first<v[i])
        {
            k=s.top().second;
            s.pop();
        }
        if(s.empty())
        {
            s.push(make_pair(v[i],i));
            k=i+1;
        }
        else
        {
            k=abs(i-s.top().second);
            s.push(make_pair(v[i],i));
        }
        span[i]=k;
        i++;
    }
}

int main()
{
    int i,j,k,n,m;
    vector<int> v{100,80,60,70,60,75,85};
    n=7;
    vector<int>span(n,0);
    stock(v,span);
    for(auto x:span)
    {
        cout<<x<<" ";
    }
    cout<<"\n";
}

