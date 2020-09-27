#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,n,m,t,tcase;
    cin>>tcase;
    while(tcase--)
    {
        cin>>t;
        vector<pair<int,int>> v;
        priority_queue<int> pq;
        k=0;
        while(t--)
        {
            cin>>n>>m;
            v.push_back(make_pair(n-k,m));
            k=n;
        }
        cin>>n>>m;
        i=0;
        int f=v[0].second;
        cout<<f<<"\n";
        int x=0,flag=0;
        while(n>0)
        {
            if(i>v.size())
            {
                flag=1;
                cout<<-1<<"\n";
                break;
            }
            if(m>=f)
            {
                pq.push(v[i].second);
            }
            else
            {
                if(pq.empty())
                {
                    flag=1;
                    cout<<-1<<"\n";
                    break;
                }
                f=f+(pq.top());
                pq.pop();
                x++;
            }
            n-=v[i].first;
            i++;
        }
        if(flag!=1)
        {
            cout<<x<<"\n";
        }
    }
}

