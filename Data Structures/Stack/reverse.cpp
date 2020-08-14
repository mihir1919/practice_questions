#include<bits/stdc++.h>
using namespace std;


void insert_at_bottom(stack<int> &s1,int x)
{
    if(s1.empty())
    {
        s1.push(x);
        return;
    }
    int t=s1.top();
    s1.pop();
    insert_at_bottom(s1,x);
    s1.push(t);
}

void rec_rev(stack<int> &s1)
{
    if(s1.empty())
    {
        return;
    }
    int x=s1.top();
    s1.pop();
    rec_rev(s1);
    if(s1.empty())
    {
        s1.push(x);
    }
    else
    {
        insert_at_bottom(s1,x);
    }

}

void rev(stack<int> &s1)
{
     stack<int> s2;
     int i=0,n=s1.size(),x=0;
     while(n-i-1>0)
     {
         x=s1.top();
         s1.pop();
         int y=n-i-1;
         while(y--)
         {
             int z=s1.top();
             s1.pop();
             s2.push(z);
         }
         s1.push(x);
         y=n-i-1;
         while(y--)
         {
             int z=s2.top();
             s2.pop();
             s1.push(z);
         }
         i++;
     }
}

void prn(stack<int> v)
{
    while(!v.empty())
    {
        cout<<v.top()<<" ";
        v.pop();
    }
    cout<<"\n";
}

int main()
{
    int i,j,k;
    stack<int> v;
    for(i=0;i<5;i++)
    {
        v.push(i);
    }
    prn(v);
    rev(v);
    prn(v);
    rec_rev(v);
    prn(v);
}
