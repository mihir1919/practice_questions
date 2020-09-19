#include<bits/stdc++.h>
using namespace std;

void rev(stack<int> s)
{
    if(s.empty())
    {
        return;
    }
    int k=s.top();
    s.pop();
    rev(s);
    s.push(k);
}

int main()
{
    int n,i,j,k;
    stack<int> s;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>k;
        s.push(k);
    }
    rev(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
