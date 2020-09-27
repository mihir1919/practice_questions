#include<bits/stdc++.h>
using namespace std;


int mk=0;
int fuel(int lefft,int dist,vector<pair<int,int>> v,int k,int i)
{
    lefft=lefft-v[i].first;
    if((i>=v.size()-1 || dist<=0) && lefft>=0)
    {
        mk=k;
        return mk;
    }
    if(lefft<0 || (mk!=0 && k>=mk))
    {
        return -1;
    }
    int yup=fuel(lefft+v[i].second,dist-v[i].first,v,k+1,i+1);
    if(yup!=-1)
    {
        int nope=fuel(lefft,dist-v[i].first,v,k,i+1);
    }
    return mk;
}

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
        k=0;
        while(t--)
        {
            cin>>n>>m;
            v.push_back(make_pair(n-k,m));
            k=n;
        }
        cin>>n>>m;
        cout<<fuel(m,n,v,0,0)<<"\n";
        mk=0;
    }
}
