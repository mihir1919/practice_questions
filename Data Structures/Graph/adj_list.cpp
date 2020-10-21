#include<bits/stdc++.h>
using namespace std;


class graph
{
      int v;
      unordered_map<int,list<int>> l;
    public:
      graph(int V)
      {
          v=V;
      }

      void AddEdge(int x,int y)
      {
          l[x].push_back(y);
          l[y].push_back(x);
      }

      void prn()
      {
          for(auto x:l)
          {
              cout<<x.first<<"->";
              for(auto y:x.second)
              {
                  cout<<y<<",";
              }
              cout<<endl;
          }
      }
};

int main()
{
    graph g(4);
    g.AddEdge(0,1);
    g.AddEdge(0,2);
    g.AddEdge(2,3);
    g.AddEdge(1,2);
    g.prn();
    return 0;   
}