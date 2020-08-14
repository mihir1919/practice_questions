#include<bits/stdc++.h>
using namespace std;

int f=-1,r=-1;

void push(vector<int> &q,int d)
{
    if(r+1>q.size())
    {
        cout<<"OverFlow";
    }
    else
    {
        r=(r+1)%q.size();
        if(f==-1)
        {
            f++;
        }
        q[r]=d;
    }
}

void pop(vector<int> &q)
{
    if(f==q.size()-1)
    {
        cout<<"Underflow";
    }
    else
    {
        f=(f+1)%q.size();
    }
}

void prn(vector<int> v)
{
    for(int i=f;i<=r;i++)
    {
        cout<<v[i]<<" ";
    }
}

int main()
{
    vector<int> q(5,0);
    push(q,1);
    push(q,2);
    push(q,3);
    push(q,4);
    pop(q);
    pop(q);
    pop(q);
    pop(q);
    pop(q);
    pop(q);
    prn(q);
}


