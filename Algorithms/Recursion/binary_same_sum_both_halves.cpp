#include<bits/stdc++.h>
using namespace std;

void bin(int n,int i,string s,int x,int y)
{
    if(i==n)
    {
        cout<<s<<"\n";
        return;
    }
    if(i==n/2 && n%2!=0)
    {
        bin(n,i+1,s+'1',x,y);
        bin(n,i+1,s+'0',x,y);
    }
    else if(i==n/2 && n%2==0)
    {
        if(x>0)
        {
            bin(n,i+1,s+'1',x-1,y);
        }
        if(y>0)
        {
            bin(n,i+1,s+'0',x,y-1);
        }
    }
    else if(i<n/2)
    {
       bin(n,i+1,s+'1',x+1,y);
       bin(n,i+1,s+'0',x,y+1);
    }
    else if(i>n/2)
    {
        if(x>0)
        {
            bin(n,i+1,s+'1',x-1,y);
        }
        if(y>0)
        {
            bin(n,i+1,s+'0',x,y-1);
        }
    }
    return;
}

int main()
{
    int i,j,k,n;
    cin>>n;
    bin(n,1,"1",1,0);
}
