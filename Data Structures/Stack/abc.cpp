#include<bits/stdc++.h>
using namespace std;

void stock(vector<int> v)
{
    vector<int> span;
    stack<int> p;
    for(int i=0;i<v.size();i++)
    {
        if(p.empty())
        {
            span.push_back(i+1);
        }
        else
        {
            while(v[p.top()]<v[i] && !p.empty())
            {
                p.pop();
            }
            if(!p.empty())
            {
                span.push_back(i-p.top());
            }
            else
            {
                span.push_back(i+1);
            }
        }
        p.push(i);
    }
    for(auto x:span)
    {
        cout<<x<<" ";
    }
    cout<<"\n";
}

int main()
{
    vector<int> s1={100,80,60,70,60,75,85};
    int i,j,k,n,m;
    stock(s1);
}
