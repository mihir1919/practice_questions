#include<bits/stdc++.h>
using namespace std;

void power_set(string s,string ans,int i)
{
    if(i==s.length())
    {
        cout<<ans<<"\n";
        return;
    }
    power_set(s,ans+s[i],i+1);
    power_set(s,ans,i+1);
}

int main()
{
    string s;
    cin>>s;
    power_set(s,"",0);
}
