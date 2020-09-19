#include<bits/stdc++.h>
using namespace std;


int main()
{
    long long i,j,k,n,m,t;
    cin>>t;

    while(t--)
    {
        vector<long long> par;
        cin>>n;
        m=n;
        vector<long long> ranks(n+1,0);
        while(m--)
        {
            string s;
            cin>>s;
            cin>>k;
            par.push_back(k);
            ranks[k]++;
        }
        sort(par.begin(),par.end());
        long long ans=0;
        int idx=0;
        for(i=1;i<=n;i++)
        {
            while(ranks[i])
            {
                ans+=abs((par[idx])-(idx+1));
                idx++;
                ranks[i]--;
            }
        }
        cout<<ans<<endl;
    }
}

