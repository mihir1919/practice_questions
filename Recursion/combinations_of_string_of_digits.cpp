#include<bits/stdc++.h>
using namespace std;

void len(string s,int i,string ans)
{
    if(i==s.length())
    {
        cout<<ans<<"\n";
        return;
    }
    if(i<s.length()-1)
    {
        len(s,i+1,ans+s[i]+" ");
    }
    len(s,i+1,ans+s[i]);
}

int main()
{
    string s;
    cin>>s;
    len(s,0,"");
}

