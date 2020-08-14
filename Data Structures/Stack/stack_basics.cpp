#include<bits/stdc++.h>
using namespace std;

int top=-1;

void push(vector<int> &v,int d)
{
    top=top+1;
    v[top]=d;
}

void pop(vector<int> v)
{
    top--;
}

void prn(vector<int> v)
{
    for(int i=0;i<=top;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    vector<int> v(100,0);
    push(v,100);
    push(v,100);
    push(v,100);push(v,100);push(v,100);
    push(v,100);
    prn(v);
}
