#include<bits/stdc++.h>
using namespace std;

int m(vector<int> v,int i)
{
    if(i==v.size())
    {
        return 0;
    }
    return(max(v[i],m(v,i+1)));
}

int main()
{
    vector<int> v={1,2,4,9,12,1,2,3};
    cout<<m(v,0);
}
