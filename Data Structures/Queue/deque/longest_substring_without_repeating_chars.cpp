#include<bits/stdc++.h>
using namespace std;

int lns(string s)
{
    unordered_map<char,int> m;
    deque<int> q;
    int maxim=0;
    for(int i=0;i<s.length();i++)
    {
        if(m[s[i]]==0)
        {
            m[s[i]]=i+1;
        }
        else
        {
            while(!q.empty() && q.front()!=m[s[i]])
            {
                q.pop_front();
            }
            if(!q.empty() && q.front()==m[s[i]])
            {
                q.pop_front();
            }
            m[s[i]]=i+1;
        }
        q.push_back(i+1);
        if(maxim<q.size())
        {
            maxim=q.size();
        }
    }
    return maxim;
}

int main()
{
    int i,j,k,n,m;
    string s;
    cin>>s;
    cout<<lns(s);
}
