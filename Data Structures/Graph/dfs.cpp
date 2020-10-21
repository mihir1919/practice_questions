#include<bits/stdc++.h>
using namespace std;

class graph
{
    map<int,list<int>> m;
    
    public:
        void addEdge(int x,int y)
        {
            m[x].push_back(y);
            m[y].push_back(x);
        }
        
        void dfs(int src)
        {
            static unordered_map<int,int> vis;
            cout<<src<<" ";
            vis[src]=1;
            for(auto x:m[src])
            {
                if(vis[x]==0)
                {
                    vis[x]=1;
                    //cout<<x<<" ";
                    return dfs(x);
                }
            }
        }

        void sp(int src,int dest)
        {
            deque<int> q;
            unordered_map<int,int> dis;
            q.push_back(src);
            for(auto x:m)
            {
                dis[x.first]=INT_MAX;
            }
            dis[src]=0;
            while(!q.empty())
            {
                // cout<<q.front()<<" ";
                int x=q.front();
                q.pop_front();
                for(auto y:m[x])
                {
                    if(dis[y]==INT_MAX)
                    {
                        dis[y]=1+dis[x];
                        q.push_back(y);
                    }
                }
            }
            for(auto x:dis)
            {
                cout<<x.first<<" "<<x.second<<"\n";
            }
        }
};

int main()
{
    int i,j,k,n,m;
    graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.dfs(0);
}
