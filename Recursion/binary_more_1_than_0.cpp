#include<bits/stdc++.h>
using namespace std;

void fn(int k,int i,int n,string s)
{
    if(s.length()==n)
    {
        cout<<s<<" ";
        return;
    }
    if(k<=i && i>=1)
    {
        fn(k+1,i-1,n,s+'0');
    }
    fn(0,i+1,n,s+'1');
}

int main()
{
    int i,j,k,n;
    cin>>n;
    fn(0,1,n,"1");
}
