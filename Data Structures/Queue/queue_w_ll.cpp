#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int d)
    {
        data=d;
        next=NULL;
    }
};

void push(node* &h,int d)
{
    if(h==NULL)
    {
        node* t=new node(d);
        h=t;
    }
    else
    {
        node* h1=h;
        while(h1->next!=NULL)
        {
            h1=h1->next;
        }
        node* t=new node(d);
        h1->next=t;
    }
}

void pop(node* &h)
{
    if(h==NULL)
    {
        cout<<"Underflow\n";
    }
    else
    {
        h=h->next;
    }
}

void prn(node* h)
{
    node* h1=h;
    while(h1!=NULL)
    {
        cout<<h1->data<<" ";
        h1=h1->next;
    }
    cout<<"\n";
}

int main()
{
    node* h=NULL;
    push(h,1);
    push(h,1);
    push(h,1);
    prn(h);
    pop(h);
    prn(h);
}
