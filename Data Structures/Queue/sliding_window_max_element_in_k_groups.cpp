#include<bits/stdc++.h>
using namespace std;

void slide(int arr[],int k,int n)
{
    deque<int> v;
    int i,j,m;
    for(i=0;i<k;i++)
    {
        if(!v.empty())
        {
            while(!v.empty() && arr[v.back()]<=arr[i])
            {
                v.pop_back();
            }
        }
        v.push_back(i);
    }

    for(i=k;i<n;i++)
    {
        cout<<arr[v.front()]<<" ";
        //remove the elements which aren't in the window
        while(!v.empty() && i-v.front()>=k)
        {
            v.pop_front();
        }
        //remove unwanted lesser elements (ie lesser than arr[i])
        while(!v.empty() && arr[v.back()]<=arr[i])
        {
            v.pop_back();
        }
        //add the element arr[i] to the queue
        v.push_back(arr[i]);
    }
    cout<<v.front()<<" ";
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
