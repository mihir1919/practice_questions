#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=0;
    vector<int> black{1,4,3};
    vector<int> white{5,6,2};
    sort(black.begin(),black.end());
    sort(white.begin(),white.end());
    for(int i=0;i<black.size();i++)
    {
        n+=abs(black[i]-white[i]);
    }
    cout<<n<<" ";
    return 0;
}
