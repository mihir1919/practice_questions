#include<bits/stdc++.h>
using namespace std;

string rev(string s,int i)
{
    if(i==-1)
    {
        return "";
    }
    return s[i]+(rev(s,i-1));
}

int main()
{
    int i,j,k;
    string s;
    cin>>s;
    cout<<rev(s,s.length()-1);
}
