#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &v,int i,int e)
{
    if(i<0 || i>e)
    {
        return;
    }
    int b=2*i;
    int c=b+1;
    if(b<=e && v[b]>v[i])
    {
        swap(v[b],v[i]);
        heapify(v,b,e);
    }
    if(c<=e && v[c]>v[i])
    {
        swap(v[c],v[i]);
        heapify(v,c,e);
    }
    return;
}

int main()
{
    int i,j,k,n,m;
    n=9;
    vector<int> v;
    v.push_back(-1);
    for(i=0;i<9;i++)
    {
        cin>>k;
        v.push_back(k);
    }
    for(i=9/2;i>=1;i--)
    {
        heapify(v,i,v.size()-1);
    }
    int e=v.size()-1;
    for(auto x:v)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    while(e>0)
    {
        //int x=v[1];
        //cout<<x<<" ";
        swap(v[1],v[e]);
        e--;
        heapify(v,1,e);
    }
    cout<<endl;
    for(auto x:v)
    {
        cout<<x<<" ";
    }
}
//4 1 3 7 8 17 2 9 10
