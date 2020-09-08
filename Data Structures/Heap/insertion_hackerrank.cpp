#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Heap
{
    vector<long> v;
    bool minHeap;
    public:
        Heap()
        {
            v.push_back(-1);
        }
        void push(long x)
        {
            v.push_back(x);
            long idx=v.size()-1;
            long parent=idx/2;
            while(idx>1 && v[idx]<v[parent])
            {
                swap(v[idx],v[parent]);
                idx=parent;
                parent=idx/2;
            }
        }

        void heapify(long idx)
        {
            if(idx>=(v.size()))
            {
                return;
            }
            long a=idx;
            long b=2*a;
            long c=b+1;
            long ma=v.size()-1;
            if(b<=ma && v[idx]>v[b])
            {
                swap(v[idx],v[b]);
                heapify(b);
            }
            if(c<=ma && v[idx]>v[c])
            {
                swap(v[idx],v[c]);
                heapify(c);
            }
            else
            {
                return;
            }
        }

        void prn()
        {
            for(auto x:v)
            {
                cout<<x<<" ";
            }
            cout<<"\n";
        }

        void pop(long x)
        {
            long idx=find(v.begin(),v.end(),x)-v.begin();
            //cout<<"pos of "<<x<<" is "<<idx<<"\n";
            swap(v[idx],v[v.size()-1]);
            //prn();
            v.pop_back();
            // prn();
            heapify(idx);
        }



        long minel()
        {
            return v[1];
        }
};


int main() {
    /* Enter your code here. Read input from STDIN. Prlong output to STDOUT */
    long i,j,k,n,m,t;
    cin>>t;
    Heap h;
    while(t--)
    {
        cin>>n;
        if(n!=3)
        {
            cin>>m;
            if(n==1)
            {
                h.push(m);
            }
            else
            {
                h.pop(m);
            }
        }
        else
        {
            cout<<h.minel()<<"\n";
        }
        //h.prn();
    }
    return 0;
}
