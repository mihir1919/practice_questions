
#include<bits/stdc++.h>
using namespace std;

bool done=false;

void fn(int n,int i,int x)
{
    //cout<<i<<" "<<x<<"\n";
    if(done)
    {
        return;
    }
    if(n==x)
    {
        cout<<i<<"\n";
        done=true;
        return;
    }
    if(x>n)
    {
        return;
    }
    if(x<((-1)*(n)))
    {
        return;
    }
    fn(n,i+1,x+i+1);
    fn(n,i+1,x-i-1);
}

int main()
{
	int i,j,t,k,n,m;
	cin>>t;
	while(t--)
	{
	    done=false;
	    cin>>n;
	    fn(n,0,0);
	    done=false;
	}
	return 0;
}
