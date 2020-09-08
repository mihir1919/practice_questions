#include<bits/stdc++.h>
using namespace std;

//unordered_map<int,int> mapp;

unordered_map<int,int> m;

void ins(vector<int> &top,int i)
{
    while(i>0)
    {
        if(m[top[i]]>m[top[i-1]])
        {
            swap(top[i],top[i-1]);
        }
        else if(m[top[i]]==m[top[i-1]] && top[i]<top[i-1])
        {
            swap(top[i],top[i-1]);
        }
        else
        {
            break;
        }
        i--;
    }
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int i,j,k,n;
		cin>>n>>j;
		vector<int> top;
		for(i=0;i<n;i++)
		{
			cin>>k;
			m[k]++;
			int x=find(top.begin(),top.end(),k)-top.begin();
			if(x>=top.size())
            {
                top.push_back(k);
                ins(top,top.size()-1);
            }
            else
            {
                ins(top,x);
            }
            for(int it=0;it<j && it<top.size();it++)
            {
                cout<<top[it]<<" ";
            }
		}
		m.clear();
	}
}


