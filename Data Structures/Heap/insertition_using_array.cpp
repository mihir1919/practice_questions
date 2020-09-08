#include<bits/stdc++.h>
using namespace std;

class Heap
{
    vector<int> v;
    bool minHeap;
public:
    Heap(int default_size=10,bool type=true)
    {
        v.reserve(default_size);
        v.push_back(-1);
        minHeap=type;
    }

    void push(int d)
    {
        v.push_back(d);
        int idx=v.size()-1;
        int parent=idx/2;
        while(idx>1 && v[idx]<v[parent])
        {
            swap(v[idx],v[parent]);
            idx=parent;
            parent=idx/2;
        }
    }

    void prn()
    {
        for(auto x:v)
        {
            cout<<x<<" ";
        }
    }

    int top()
    {
        return v[1];
    }

    void heapify(int idx)
    {
        if(idx>=v.size())
        {
            return;
        }
        int a=idx;
        int b=2*a;
        int c=b+1;
        int ma=v.size()-1;
        int mi=a;
        if(idx<=ma && v[idx]>v[b])
        {
            swap(v[idx],v[b]);
            heapify(b);
        }
        if(idx<=ma && v[idx]>v[c])
        {
            swap(v[idx],v[c]);
            heapify(c);
        }
        else
        {
            return;
        }
    }

    void pop()
    {
        swap(v[v.size()-1],v[1]);
        v.pop_back();
        heapify(1);
    }
};

int main()
{
    Heap h;
    h.push(1);
    h.push(2);
    h.push(3);
    h.push(17);
    h.push(19);
    h.push(30);
    h.push(7);
    h.push(25);
    h.push(100);
    //h.prn();
    h.push(0);
    h.pop();
    h.prn();
}
