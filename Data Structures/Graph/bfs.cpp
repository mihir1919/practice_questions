#include<bits/stdc++.h>
using namespace std;

<<<<<<< Updated upstream

class graph
{
    map<int,list<int>> l;
    public:
      void AddEdge(int x,int y)
      {
          l[x].push_back(y);
          l[y].push_back(x);
      }

      void bfs(int src)
      {
          map<int,int> visited;
          deque<int> q;
          q.push_back(src);
          visited[src]=1;
          while(!q.empty())
          {
              cout<<q.front()<<" ";
              int x=q.front();
              q.pop_front();
              for(auto y:l[x])
              {
                  if(visited[y]==0)
                  {
                      q.push_back(y);
                      visited[y]=1;
                  }
              }
          }
      }


      void shortest_path(int src,int dest)
      {
          map<int,int> vis;
          for(auto x:l)
          {
              vis[x.first]=INT_MAX;
          }
          vis[src]=0;
          deque<int> q;
          q.push_back(src);
          while(!q.empty())
          {
              int x=q.front();
              q.pop_front();
              cout<<x<<" ";
              for(auto y:l[x])
              {
                  if(vis[y]==INT_MAX)
                  {
                      vis[y]=1+vis[x];
                      q.push_back(y);
                  }
              }
          }
          for(auto x:vis)
          {
              cout<<x.first<<" "<<x.second<<"\n";
          }
      }
=======
class graph
{
    map<int,list<int>> m;
    
    public:
        void addEdge(int x,int y)
        {
            m[x].push_back(y);
            m[y].push_back(x);
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
>>>>>>> Stashed changes
};

int main()
{
<<<<<<< Updated upstream
    graph g;
    g.AddEdge(0,1);
    g.AddEdge(1,2);
    g.AddEdge(2,3);
    g.AddEdge(0,3);
    g.AddEdge(3,4);
    g.AddEdge(4,5);
    g.shortest_path(0,5);
    return 0;   
}
=======
    int i,j,k,n,m;
    graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.sp(0,5);
}
>>>>>>> Stashed changes
