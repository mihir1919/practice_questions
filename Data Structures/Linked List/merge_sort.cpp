#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int d)
    {
        data=d;
        next=NULL;
    }
};

node* tail(node* &head,int d)
{
    node* t=new node(d);
    if(head!=NULL)
    {
        node* h=head;
        while(h->next!=NULL)
        {
            h=h->next;
        }
        h->next=t;
    }
    else
    {
        head=t;
    }
    return head;
}

void prnt(node* head)
{
    if(head==NULL)
    {
        cout<<"\n";
        return;
    }
    cout<<head->data<<" ";
    prnt(head->next);
}

node* middle(node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node* h=head;
    node* f=head->next;
    while(f!=NULL && f->next!=NULL)
    {
        f=f->next->next;
        h=h->next;
    }
    return h;
}

node* mergee(node* &a,node* &b)
{
    node* c;
    if(a==NULL)
    {
        return b;
    }
    if(b==NULL)
    {
        return a;
    }
    if(a->data < b->data)
    {
        c=a;
        c->next=(mergee(a->next,b));
    }
    else
    {
        c=b;
        c->next=(mergee(a,b->next));
    }
    prnt(c);
    return c;
}

node* merge_sort(node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    prnt(head);
    node* mid=middle(head);
    node* temp;
    temp=mid->next;
    mid->next=NULL;
    node* b=merge_sort(temp);
    node* a=merge_sort(head);
    node* c=mergee(b,a);
    return c;
}

int main()
{
    node* head=NULL;
    tail(head,5);
    tail(head,4);
    tail(head,3);
    tail(head,2);
    tail(head,1);
    merge_sort(head);
    prnt(head);
}
