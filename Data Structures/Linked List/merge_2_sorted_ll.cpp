#include<bits/stdc++.h>
using namespace std;
#include "fn.h"

node* merge_ll(node* &head1,node* &head2)
{
    if(head1==NULL)
    {
        return head2;
    }
    else if(head2==NULL)
    {
        return head1;
    }
    node* c;
    if(head1->data>head2->data)
    {
        c=head2;
        c->next=merge_ll(head1,head2->next);
    }
    else
    {
        c=head1;
        c->next=merge_ll(head1->next,head2);
    }
    return c;
}

int main()
{
    node* head=NULL;
    //buildll(head);
    intail(head,1);
    intail(head,2);
    intail(head,6);
    intail(head,7);
    //intail(head,5);

    node* head2=NULL;
    intail(head2,2);
    intail(head2,5);
    intail(head2,6);
    intail(head2,8);
    prn(head);
    prn(head2);
    merge_ll(head,head2);
    prn(head);
}
/*

node* merge_ll(node* &head1,node* &head2)
{
    if(head1==NULL)
    {
        return head2;
    }
    else if(head2==NULL)
    {
        return head1;
    }
    node* c;
    if(head1->data>head2->data)
    {
        c=head2;
        c->next=merge_ll(head1,head2->next);
    }
    else
    {
        c=head1;
        c->next=merge_ll(head1->next,head2);
    }
    return c;
}


node* middle(node* head,node* n)
{
    if(n==NULL || n->next==NULL)
    {
        return head;
    }
    return middle(head->next,n->next->next);
}

node* merge_sort(node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node* mid=middle(head,head);
    node* a=head;
    node* b=mid->next;
    mid->next=NULL;    cout<<"f";
    a=merge_sort(a);
    b=merge_sort(b);
    return merge_ll(a,b);
}
*/
