#include<bits/stdc++.h>
using namespace std;
#include "fn.h"

node* merge_ll(node* &head1,node* &head2)
{
    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
    node* c;
    if(head1->data<head2->data)
    {
        c=head1;
        c->next=merge_ll(head1->next,head2);
    }
    else
    {
        c=head2;
        c->next=merge_ll(head1,head2->next);
    }
    return c;
}

node* middle(node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node* h=head;
    node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        h=h->next;
        fast=fast->next->next;
    }
    return h;
}

node* merge_sort(node* head)
{
    //prn(head);
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    //prn(head);
    node* mid=middle(head);
    //cout<<mid->data<<" ";
    //
    node* a=head;
    node* b=mid->next;
    mid->next=NULL;
    a=merge_sort(a);
    b=merge_sort(b);
    node* c=merge_ll(a,b);
    return c;
}

int main()
{
    node* head=NULL;
    //buildll(head);
    intail(head,5);intail(head,4);
    intail(head,3);intail(head,2);
    intail(head,1);


    //intail(head,5);
    node* h=head;
    merge_sort(head);
    prn(h);
}

