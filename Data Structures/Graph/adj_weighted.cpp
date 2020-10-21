#include<bits/stdc++.h>
using namespace std;


class graph
{
      int v;
      unordered_map<string,list<pair<string,int>>> l;
    public:
      void AddEdge(string x,string y,bool bi=true,int wt=0)
      {
          l[x].push_back(make_pair(y,wt));
          if(bi)
          {
              l[y].push_back(make_pair(x,wt));
          }
      }

      void prn()
      {
          for(auto x:l)
          {
              cout<<x.first<<"->";
              for(auto y:x.second)
              {
                  cout<<y.first<<"("<<y.second<<"),";
              }
              cout<<endl;
          }
      }
};

int main()
{
    graph g;
    g.AddEdge("a","b",true,20);
    g.AddEdge("b","d",true,40);
    g.AddEdge("a","c",true,10);
    g.AddEdge("c","d",true,40);
    g.AddEdge("a","d",false,50);
    g.prn();
    return 0;   
}