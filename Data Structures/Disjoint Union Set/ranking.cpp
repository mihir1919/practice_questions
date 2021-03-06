#include<bits/stdc++.h>
using namespace std;

class graph
{
    unordered_map<int,int> parent;
    vector<pair<int,int>> l;
    unordered_map<int,int> rank_s;
    public:
        void addEdge(int x,int y)
        {
            l.push_back(make_pair(x,y));
            parent[x]=-1;
            parent[y]=-1;
            rank_s[x]=1;
            rank_s[y]=1;
        }

        int find_s(int x)
        {
            if(parent[x]==-1)
            {
                return x;
            }
            return find_s(parent[x]);
        }

        void union_s(int x,int y)
        {
            int s1=find_s(x);
            int s2=find_s(y);
            if(s1!=s2)
            {
                parent[s2]=s1;
            }
        }

        bool cycle_present(int V)
        {
            for(auto x:l)
            {
                int a=x.first;
                int b=x.second;
                int s1=find_s(a);
                int s2=find_s(b);
                if(s1!=s2)
                {
                    if(rank_s[s1]>rank_s[s2])
                    {
                        rank_s[s1]+=rank_s[s2];
                        parent[s2]=s1;
                    }
                    else
                    {
                        rank_s[s2]+=rank_s[s1]; 
                        parent[s1]=s2;
                    }
                    
                }
                else
                {
                    for(auto x:rank_s)
                    {
                        cout<<x.first<<" "<<x.second<<"\n";
                    }
                    return true;
                }
            }
            
                    for(auto x:rank_s)
                    {
                        cout<<x.first<<" "<<x.second<<"\n";
                    }
            return false;
        }

};

int main()
{
    int i,j,k,n,m;
    graph g;
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    //g.addEdge(4,1);
    cout<<g.cycle_present(4);
    // g.addEdge(2,5);
    // cout<<"S";
}