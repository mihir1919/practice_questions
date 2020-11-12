#include<bits/stdc++.h>
using namespace std;

class graph
{
    vector<pair<long long,pair<long long,long long>>> m;
    vector<long long> arr;
    vector<long long> v;
    public:

       class mycmp{
            public:
                bool operator()(pair<long long,pair<long long,long long>> a,pair<long long,pair<long long,long long>> b){
                    return a.second.second<b.second.second;
                }
       };
        void addEdge(long long a,long long b,long long c)
        {
            m.push_back(make_pair(a,make_pair(b,c)));
            m.push_back(make_pair(b,make_pair(a,c)));
        }

        long long find_s(long long a)
        {
            if(arr[a]==-1)
            {
                return a;
            }
            return arr[a]=find_s(arr[a]);
        }

        long long union_s(long long a,long long b)
        {
            long long s1=find_s(a);
            long long s2=find_s(b);
            if(s1!=s2)
            {
                arr[s2]=s1;
                return 1;
            }
            else
            {
                return -1;
            }
        }

        long long kruskal()
        {
            for(long long i=0;i<=m.size();i++)
            {
                arr.push_back(-1);
            }
            long long s=0;
            sort(m.begin(),m.end(),mycmp());
            for(auto x:m)
            {
                long long e=union_s(x.first,x.second.first);
                if(e==1)
                {
                    cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<"\n";
                    s+=x.second.second;
                }
            }
            // for(auto x:arr)
            // {
            //     cout<<x<<" ";
            // }
            return s;
        }


};

int main()
{
    graph g;
    long long i,j,k,n,m,x,y,z;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>x>>y>>z;
        g.addEdge(x,y,z);
    }
    // g.addEdge(1,2,1);
    // g.addEdge(2,4,3);
    // g.addEdge(4,3,3);
    // g.addEdge(3,1,2);
    // g.addEdge(1,4,2);
    // g.addEdge(2,3,2);
    cout<<g.kruskal()<<"\n";
}
