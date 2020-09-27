#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<long long,long long> a,pair<long long,long long> b)
{
	return a.first<b.first;
}

long long act(vector<pair<long long,long long>> v)
{
	long long m=LONG_MIN,i=0,j,k=0;
	sort(v.begin(),v.end(),cmp);
	while(i<v.size())
	{
		if(v[i].first>=m)
		{
			k++;
			m=v[i].second;
		}
		i++;
	}
	return v.size()-k;
}


int main() {
	long long i,j,k,n,m;
	cin>>n;
	vector<pair<long long,long long>> v;
	for(i=0;i<n;i++)
	{
		cin>>j>>k;
		v.push_back(make_pair(j-k,j+k));
	}
	cout<<act(v)<<"\n";
	return 0;
}
