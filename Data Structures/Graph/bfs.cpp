#include<bits/stdc++.h>
using namespace std;


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
};

int main()
{
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
