#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,n,m,a,b;
    vector<int> x;
    vector<int> y;
    cin>>n>>m>>k;
    for(i=0;i<k;i++)
    {
        cin>>a>>b;
        x.push_back(a);
        y.push_back(b);
    }
    x.push_back(0);
    y.push_back(0);
    x.push_back(n);
    y.push_back(m);
    int dx=0;
    int dy=0;
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    for(i=0;i<x.size()-1;i++)
    {
        if(x[i+1]==n)
        {
            dx=max(dx,abs(x[i]-x[i+1]));
        }
        if(y[i+1]==m)
        {
            dy=max(dy,abs(y[i]-y[i+1]));
        }
        else
        {
            dx=max(dx,abs(x[i]-x[i+1])-1);
            dy=max(dy,abs(y[i]-y[i+1])-1);
        }

    }
    cout<<dx*dy<<" ";
}
//15 8 3 3 8 11 2 8 6
