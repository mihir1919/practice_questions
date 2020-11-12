#include<bits/stdc++.h>
using namespace std;

class graph
{
    map<int,list<int>> m;
    unordered_map<int,int> vis;
    unordered_map<int,int> par;
    public:
        void addEdge(int x,int y)
        {
            m[x].push_back(y);
            m[y].push_back(x);
        }

        bool dfs(int x)
        {
            bool z=true;
            vis[x]=1;
            for(auto y:m[x])
            {
                if(y==par[x])
                {
                    continue;
                }
                if(vis[y]==1)
                {
                    return false;
                }
                par[y]=x;
                vis[y]=1;
                z=(true)&&(dfs(y));
            }
            return z;
        }

        bool dfs_helper()
        {
            return dfs(0);
        }

};

int main()
{
    int i,j,k,n,m;
    graph g;
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    // g.addEdge(2,5);
    cout<<g.dfs_helper();
    // cout<<"S";
}