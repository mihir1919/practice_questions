#include<bits/stdc++.h>
using namespace std;

void power_set(string s,string ans,int i)
{
    if(i==s.length())
    {
        cout<<ans<<" ";return;
    }

    for(int j=i;j<s.length();j++)
    {
        ans+=s[j];
        cout<<ans<<"\n";
    }
    power_set(s,"",i+1);
}

int main()
{
    string s;
    cin>>s;
    power_set(s,"",0);
}
