#include<bits/stdc++.h>
using namespace std;

template<typename T>
class st1{
    queue<T> q1;
    queue<T> q2;
public:
    void push(T x)
    {
        q1.push(x);
    }

    void popit()
    {
        if(q2.empty())
        {
        while(!q1.empty())
        {
                T z=q1.front();
                q1.pop();
                if(q1.empty())
                {
                    break;
                }
                q2.push(z);
            }
            queue<T> temp=q1;
            q1=q2;
            q2=temp;
        }
        else
        {
            while(!q2.empty())
            {
                T z=q2.front();
                q2.pop();
                if(q2.empty())
                {
                    break;
                }
                q2.push(z);
            }
            queue<T> temp=q1;
            q1=q2;
            q2=temp;
        }
    }

    void prn()
    {
        if(q1.empty())
        {
            return;
        }
        int x=q1.front();
        q1.pop();
        prn();
        cout<<x<<" ";
    }
};

int main()
{
    int i,j,k,n,m;
    st1<int> s;
    s.push(3);
    s.push(5);
    s.prn();
    s.push(6);
    s.prn();
    s.pop();
    s.prn();
}
