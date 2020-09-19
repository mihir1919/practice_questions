#include<bits/stdc++.h>
using namespace std;

bool isp(string k)
{
    if(k.size()==1 || k.size()==0)
    {
        return true;
    }
    if(k[0]!=k[k.length()-1])
    {
        return false;
    }
    return true&&isp(k.substr(1,k.length()-2));
}
int main()
{
    int n,i,j;
    string k;
    cin>>n;
    while(n--)
    {
        cin>>k;
        cout<<(isp(k)==true?"Yes\n":"No\n");
    }
}
