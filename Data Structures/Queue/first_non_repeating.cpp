#include<bits/stdc++.h>
using namespace std;

char fnrc(string s)
{
    queue<char> q;
    unordered_map<char,int> m;
    for(char c:s)
    {
        q.push(c);
        m[c]++;
        if(m[q.front()]==1)
        {
            cout<<q.front()<<" ";
        }
        else
        {
            cout<<"-1 ";
            while(!q.empty())
            {
                q.pop();
            }
        }
    }
}

void prn(queue<char> q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}

int main()
{
    string s="aabccbcd";
    fnrc(s);
}
