#include<bits/stdc++.h>
using namespace std;

void power_set(string s,string ans,int i)
{
    if(i==s.length())
    {
        cout<<ans<<"\n";return;
    }
    for(int k=i;k<s.length();k++)
    {
        power_set(s,ans+s[k],i+1);

        //power_set(s,ans,i+1);
    }
    return;
}

int main()
{
    string s;
    cin>>s;
    power_set(s,"",0);
}
