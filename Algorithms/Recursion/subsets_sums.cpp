#include<bits/stdc++.h>
using namespace std;

int i,t,m,j,k,n;
vector<int> ans;
void fn(vector<int> arr,int n,int i,int s)
{
    if(i==n)
    {
        ans.push_back(s);
        return;
    }
    fn(arr,n,i+1,s+arr[i]);fn(arr,n,i+1,s);

}

int main()
 {
	//code
	//int i,t,m,j,k,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    vector<int>arr(n);
	    for(i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }

	    fn(arr,n,0,0);
	    //sort(ans.begin(),ans.end());
	    for(auto x:ans)
	    {
	        cout<<x<<" ";
	    }
	    cout<<"\n";
	    ans.clear();
	}
	return 0;
}
