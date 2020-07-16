#include<bits/stdc++.h>
using namespace std;

char vow[6]={'a','e','i','o','u',' '};

int len(string s)
{
    if(s=="")
    {
        return 0;
    }
    return 1+len(s.substr(1,s.length()-1));
}

int main()
{
    string s;
    cin>>s;
    cout<<len(s);
}

