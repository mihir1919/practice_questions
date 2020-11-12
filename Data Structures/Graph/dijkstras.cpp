#include<bits/stdc++.h>
using namespace std;

class graph
{
    unordered_map<int,list<pair<int,int>>> m;
    set<pair<int,int>> dis;
    public:
        void addEdge(int x,int y,int dis)
        {
            m[x].push_back(make_pair(y,dis));
            m[y].push_back(make_pair(x,dis));
        }

        void shortest_dis(int src)
        {
            for(auto x:m[src])
            {
                dis.insert(make_pair(x.second,x.first));
            }
            int y=0;
            int z=src;
            for(auto x:dis)
            {
                int d_z_2_x=0;
                for(auto d:m[z])
                {
                    if(d.first==x.second)
                    {
                        d_z_2_x=d.second;
                        break;
                    }
                }
                if(y+d_z_2_x<x.first)
                {
                    x.first=y+d_z_2_x;
                }
                y=x.first;
                z=x.second;
                cout<<y<<" "<<z<<"\n";
            }
        }

};

int main()
{
    int i,j,k,n,m;
    graph g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,5);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);
    g.shortest_dis(1);
}