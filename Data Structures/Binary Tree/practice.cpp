#include<bits/stdc++.h>
using namespace std;

auto compare(int a,int b)
{
    cout<<a<<" "<<b<<"\n";
    return a>=b;
}

int main()
{
    vector<int> v={1,2,5,10,50,100,200,500};
    int x=16;
    cout<<*lower_bound(v.begin(),v.end(),x,compare);
}
