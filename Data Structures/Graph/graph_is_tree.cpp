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

        bool bfs_helper(int src)
        {
            deque<int> q;
            q.push_back(src);
            vis[src]=1;
            while (!q.empty())
            {
                int x=q.front();
                q.pop_front();
                for(auto y:m[x])
                {
                    if(y==par[x])
                    {
                        continue;
                    }
                    if(vis[y]==1 && y!=par[x])
                    {
                        return 0;
                    }
                    vis[y]=1;
                    par[y]=x;
                    q.push_back(y);
                }
            }
            return 1;
        }

};

int main()
{
    int i,j,k,n,m;
    graph g;
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(2,5);
    cout<<g.bfs_helper(0);
}