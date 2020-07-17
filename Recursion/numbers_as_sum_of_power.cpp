#include<bits/stdc++.h>
using namespace std;

void funct(int x,int n,int i,int m,int* ptr)
{
    if(x==0)
    {
        *ptr=*ptr+1;
        return;
    }
    if(x<0 || i>m)
    {
        return;
    }
    if(pow(i,n)<=x)
    {
        funct(x-pow(i,n),n,i+1,m,ptr);
        funct(x,n,i+1,m,ptr);
    }
    else
    {
        funct(x,n,i+1,m,ptr);
    }
    return;
}

int main()
{
    int i,j,k,x,n,m;
    cin>>x>>n;
    m=pow(x,float(float(1)/float(n)));
    //cout<<m;
    k=0;
    int* ptr=&k;
    funct(x,n,1,m,ptr);
    cout<<*ptr<<"\n";
    k=0;
}
