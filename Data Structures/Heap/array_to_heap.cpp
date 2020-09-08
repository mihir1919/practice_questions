#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &v,int i)
{
    if(i<0 || i>=v.size())
    {
        return;
    }
    int b=2*i;
    int c=b+1;
    if(b<=v.size()-1 && v[b]>v[i])
    {
        swap(v[b],v[i]);
        heapify(v,b);
    }
    if(c<=v.size()-1 && v[c]>v[i])
    {
        swap(v[c],v[i]);
        heapify(v,c);
    }
    return;
}

int main()
{
    int i,j,k,n,m;
    n=9;
    vector<int> v;
    v.push_back(-1);
    for(i=0;i<9;i++)
    {
        cin>>k;
        v.push_back(k);
    }
    for(i=9/2;i>=1;i--)
    {
        heapify(v,i);
    }
//    for(i=1;i<=9;i++)
//    {
//        int parent=i/2;
//        if(parent>0 && v[parent]<v[i])
//        {
//            int p=parent;
//            int idx=i;
//            while(v[idx]>v[p] && p>0)
//            {
//                swap(v[idx],v[p]);
//                idx=p;
//                p=idx/2;
//            }
//        }
//        cout<<v[i]<<" "<<v[parent]<<"\n";
//    }
    for(auto x:v)
    {
        cout<<x<<" ";
    }
}
//4 1 3 7 8 17 2 9 10
