#include<bits/stdc++.h>
using namespace std;

void bin(int n,string s)
{
    if(n==0)
    {
        cout<<s<<"\n";
        return;
    }
    if(s.length()>0 && s[s.length()-1]=='0')
    {
        bin(n-1,s+'1');
    }
    else if(s.length()==0)
    {
        bin(n-1,s+'1');
    }
    bin(n-1,s+'0');
}

int main()
{
    int i,j,n,k;
    cin>>n;
    string s="";
    bin(n,s);
}
