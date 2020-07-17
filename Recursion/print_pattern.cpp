#include<bits/stdc++.h>
using namespace std;

int i,t,m,j,k,n;

void fn(int m,bool neg,int n)
{
    if(n==m)
    {
        cout<<n<<"\n";
        return;
    }
    if(n>0 && neg)
    {
        cout<<n<<" ";
        fn(m,neg,n+5);
    }
    else if(n>0 && !neg)
    {
        cout<<n<<" ";
        fn(m,neg,n-5);
    }
    if(n<=0)
    {
        cout<<n<<" ";
        fn(m,true,n+5);
    }
    return;
}
int main()
 {
	//code
	//int i,t,m,j,k,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    m=n;
	    bool neg;
	    cout<<n<<" ";
	    n=n-5;
	    fn(m,neg,n);
	}
	return 0;
}
