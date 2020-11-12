#include<bits/stdc++.h>
using namespace std;

class graph
{
    unordered_map<int,list<pair<int,pair<int,int>>>> m;
    set<pair<int,int>> dist_set;


    public:
        void addEdge(int x,int y,int distances_t,int distances_f)
        {
            m[x].push_back(make_pair(y,make_pair(distances_t,distances_f)));
            m[y].push_back(make_pair(x,make_pair(distances_t,distances_f)));
        }

        void shortest_dis(int src,unordered_map<int,int> &dis)
        {
            for(auto x:m[src])
            {
                x.first;
            }

        }

        int icpc_helper(int src,int des)
        {
            unordered_map<int,int> dis1;
            unordered_map<int,int> dis2;
            shortest_dis(src,dis1);
            shortest_dis(des,dis2);
        }
};

int main()
{
    int i,j,k,n,m;
    graph g;
    g.addEdge(1,2,1,4);
    g.addEdge(1,3,4,5);
    g.addEdge(2,3,5,2);
    g.addEdge(3,4,2,3);
    g.addEdge(1,4,7,6);
    cout<<g.icpc_helper(1,4);
}