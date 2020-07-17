#include<bits/stdc++.h>
using namespace std;

int mul(int x,int j)
{
    if(j==0)
    {
        return 0;
    }
    return x+(mul(x,j-1));
}

int main()
{
    int x,i,j,k;
    cin>>x>>j;
    cout<<mul(x,j);
}
