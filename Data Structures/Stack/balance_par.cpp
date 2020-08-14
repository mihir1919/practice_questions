#include<bits/stdc++.h>
using namespace std;

bool balanced(string s,stack<char> v)
{
    if(s.length()==0)
    {
        if(v.empty())
        {
            return true;
        }
        else{
            return false;
        }
    }
    if(!v.empty())
    {
        if(s[0]=='(' && v.top()==')')
        {
            return false;
        }
        else if(s[0]=='(' && v.top()=='(')
        {
            v.push(s[0]);
        }
        else if(s[0]==')')
        {
            if(v.top()=='(')
            {
                v.pop();
            }
            else
            {
                v.push(s[0]);
            }
        }
    }
    else
    {
        if(s[0]==')')
        {
            return false;
        }
        else if(s[0]=='(')
        {
            v.push(s[0]);
        }
    }
    return true&&(balanced(s.substr(1,s.length()-1),v));
}

int main()
{
    int i,j,k,n,m;
    stack<char> v;
    string s="((a+b)*(c))";
    cout<<balanced(s,v);
}
