#include<bits/stdc++.h>
using namespace std;

int change(vector<int> coins,int s)
{
    while(s>0)
    {
        int x=upper_bound(coins.begin(),coins.end(),s)-coins.begin();
        s-=coins[x-1];
        cout<<coins[x-1]<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> coins={1,2,5,10,20,50,100,200,500,1000,2000};
    change(coins,n);
    return 0;
}
