#include<bits/stdc++.h>
using namespace std;

int comp(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b)
{
    if(a.second.second==b.second.second)
    {
        return a.second.first>b.second.first;
    }
    return a.second.second<b.second.second;
}

int fn(vector<pair<int,pair<int,int>>> act)
{
    int ans=0;
    int i=0,j,k;
    int t=INT_MIN;
    while(i<act.size())
    {
        if((act[i]).second.first>=t)
        {
            //cout<<act[i].first<<"
            ans++;
            t=(act[i]).second.second;
        }
        i++;
    }
    //cout<<endl;
    return ans;
}

int main()
{
    int cases;
    cin>>cases;
    int n,x,a,y,i,j,k,jj;
    while(cases--)
    {
        cin>>n;
        vector<int> act;
        vector<pair<int,pair<int,int>>> t;
        for(i=0;i<n;i++)
        {
            cin>>x>>y;
            t.push_back(make_pair(i,make_pair(x,y)));
        }
        sort(t.begin(),t.end(),comp);
//        for(auto x:t)
//        {
//            cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<"\n";
//        }
        cout<<fn(t)<<endl;
    }
}

//5 3 8 7 9 1 3 3 5 4 6
