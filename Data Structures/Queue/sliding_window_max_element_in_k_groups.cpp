#include<bits/stdc++.h>
using namespace std;

void slide(int arr[],int k,int n)
{
    deque<int> v;
    int m=INT_MIN;
    int f=0;
    for(int i=0;i<n;i++)
    {
        if(f==0)
        {
            for(int j=0;j<k;j++)
            {
                v.push_back(arr[j]);
                if(m<arr[j])
                {
                    m=arr[j];
                }
            }
            f=1;
            i+=k-1;
        }
        else
        {
            v.pop_front();
            m=max(m,arr[i]);
            v.push_back(arr[i]);
        }
        cout<<m<<" ";
    }
    cout<<"\n";
}

int main()
{
	int n;
	cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    }
    int k;
    cin>>k;
    slide(arr,k,n);
}
