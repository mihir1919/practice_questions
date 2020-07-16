#include<bits/stdc++.h>
using namespace std;

void part(string s,int i,int j,bool isp,string ans)
{
    if(i<0 || j>=s.length())
    {
        cout<<ans<<"\n";
        return;
    }
    if(isp)
    {
        if(s[i]==s[j])
        {
            part(s,i-1,j+1,true,s[i]+ans+s[j]);
            part(s,i-1,j+1,false,s[i]+" "+ans+" "+s[j]);
        }
        else
        {
            part(s,i-1,j+1,false,s[i]+" "+ans+" "+s[j]);
        }
    }
    else
    {
            part(s,i-1,j+1,false,char(s[i])+" "+ans+" "+s[j]);
    }
    return;
}

int main()
{
    string s;
    int i,j,k;
    cin>>s;
    part(s,(s.length())/2,(s.length()/2),true,"");
}
