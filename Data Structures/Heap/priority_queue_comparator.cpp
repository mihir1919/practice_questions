#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    string s;
    int age;

    Person(string n,int a)
    {
        s=n;
        age=a;
    }
};

class PersonCompare
{
public:
    bool operator()(Person a,Person b)
    {
        return a.age<b.age;
    }
};

int main()
{
    priority_queue<Person,vector<Person>,PersonCompare> pq;
    int i,j,k,n;
    cin>>n;
    string s;
    for(i=0;i<n;i++)
    {
        cin>>s>>k;
        Person p(s,k);
        pq.push(p);
    }
    while(!pq.empty())
    {
        cout<<pq.top().s<<" "<<pq.top().age<<" ";
        pq.pop();
    }
}

