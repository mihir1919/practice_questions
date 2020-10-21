#include<bits/stdc++.h>
using namespace std;

class graph
{
    map<int,list<int>> m;
    unordered_map<int,int> in_deg;
    public:
        void addEdge(int x,int y)
        {
            m[x].push_back(y);
        }

        void bfs_helper()
        {
            for(auto x:m)
            {
                if(in_deg[x.first]==0)
                {
                    in_deg[x.first]==0;
                }
                for(auto y:x.second)
                {
                    in_deg[y]++;
                }
            }
            deque<int> q;
            for (auto x:in_deg)
            {
                if(in_deg[x.first]==0)
                {
                    q.push_back(x.first);
                }
            }
            while(!q.empty())
            {
                int x=q.front();
                q.pop_front();
                cout<<x<<" ";
                for(auto y:m[x])
                {
                    if(in_deg[y]==0)
                    {
                        continue;
                    }
                    in_deg[y]--;
                    if(in_deg[y]==0)
                    {
                        q.push_back(y);
                    }
                }
            }
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
    g.addEdge(4,5);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.bfs_helper();
}