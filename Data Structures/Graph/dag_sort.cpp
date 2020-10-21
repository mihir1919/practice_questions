#include<bits/stdc++.h>
using namespace std;

class graph
{
    
    map<int,list<int>> m;
    
    public:
        void addEdge(int x,int y)
        {
            m[x].push_back(y);
        }
        
        bool cmp(pair<int,int> m,pair<int,int> n)
        {
            return m.first>n.first;
        }

        void dfs(int src,map<int,int> &vis,stack<int> &s)
        {
            //cout<<src<<" ";
            vis[src]=1;
            for(auto x:m[src])
            {
                if(vis[x]==0)
                {
                    vis[x]=1;
                    //cout<<x<<" ";
                    dfs(x,vis,s);
                }
            }
            s.push(src);
        }

        void dfs_helper()
        {
            map<int,int> vis;
            stack<int> s;
            for(auto x:m)
            {
                //cout<<x.first<<" mapval\n";
                if(vis[x.first]==0)
                {
                    dfs(x.first,vis,s);
                }
                //cout<<"\n";
            }
            while(!s.empty())
            {
                cout<<s.top()<<" ";
                s.pop();
            }
        }

};

int main()
{
    int i,j,k,n,m;
    graph g;
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1);
    g.dfs_helper();
}
