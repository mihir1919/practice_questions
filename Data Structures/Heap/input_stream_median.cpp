#include<bits/stdc++.h>
using namespace std;

void prn(priority_queue<int,vector<int>,greater<int>> pq1)
{
    if(pq1.size()==0)
    {
        return;
    }
    int x=pq1.top();
    pq1.pop();
    cout<<x<<" ";
    prn(pq1);
    pq1.push(x);
}

void prn_max(priority_queue<int> pq1)
{
    if(pq1.size()==0)
    {
        return;
    }
    int x=pq1.top();
    pq1.pop();
    prn_max(pq1);
    cout<<x<<" ";
    pq1.push(x);
}

int main()
{
    priority_queue<int> pq1;
    priority_queue<int,vector<int>,greater<int>> pq2;
    int i,j,k,t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        float med=INT_MIN;
        for(int i=0;i<n;i++)
        {
            cin>>k;
            if(pq1.size()>pq2.size())
            {
                if(k>=med)
                {
                    pq2.push(k);
                }
                else
                {
                    pq2.push(pq1.top());
                    pq1.pop();
                    pq1.push(k);
                }
            }
            else if(pq1.size()==pq2.size())
            {
                if(k>=med)
                {
                    pq2.push(k);
                }
                else
                {
                    pq1.push(k);
                }
            }
            else
            {
                if(k<=med)
                {
                    pq1.push(k);
                }
                else
                {
                    pq1.push(pq2.top());
                    pq2.pop();
                    pq2.push(k);
                }
            }
            int A=0,B=0;
            if(pq1.size()!=0)
            {
                A=pq1.top();
            }
            if(pq2.size()!=0)
            {
                B=pq2.top();
            }
            if(pq1.size()==pq2.size())
            {
                med=(A+B)/2;
            }
            else if(pq1.size()>pq2.size())
            {
                med=A;
            }
            else
            {
                med=B;
            }
//            prn_max(pq1);
//            cout<<"--";
//            prn(pq2);
//            cout<<endl;
            cout<<med<<" ";
        }
    }
}
