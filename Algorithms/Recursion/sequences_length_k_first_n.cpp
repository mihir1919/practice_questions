#include<bits/stdc++.h>
using namespace std;

void bin(int n,int k,int i,int j,string ans)
{

    if(ans.length()==k*2)
    {
        ans.erase(ans.length()-1,1);
        cout<<ans<<"\n";
        return;
    }
    if(j==n+1)
    {
        return;
    }
    bin(n,k,i+1,j+1,ans+(to_string(j)+" "));
    bin(n,k,i+1,j+1,ans);
    return;
}

int main()
{
    int i,j,k,n,m;
    cin>>k>>n;
    bin(n,k,1,1,"");
}
