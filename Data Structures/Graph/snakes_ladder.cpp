#include<bits/stdc++.h>
using namespace std;

class graph
{
    map<int,list<int>> m;
    unordered_map<int,int> parent;
    public:
        void addEdge(int x,int y)
        {
            m[x].push_back(y);
        }

        int sp(int src,int dest)
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
                        parent[y]=x;
                    }
                }
            }
            int temp=dest;
            while(temp!=src)
            {
                cout<<temp<<"=>";
                temp=parent[temp];
            }
            return dis[dest];
        }
};

int main()
{
    int i,j,k,n,m;
    graph g;
    int board[50]={0};
    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=10;
    board[32]=-2;
    board[34]=-22;
    for(int i=0;i<=36;i++)
    {
        for (int j = 1; j <=6; j++)
        {
            /* code */
            int d=i+j;
            d+=(board[d]);
            if(d<=36)
            {
                g.addEdge(i,d);
            }
        }
    }
    g.addEdge(36,36);
    cout<<g.sp(0,36);
}