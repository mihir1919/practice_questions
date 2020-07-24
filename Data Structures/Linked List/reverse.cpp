#include<bits/stdc++.h>
using namespace std;
#include "fn.h"


void iterative_reverse(node* &head)
{
    node* curr=head;
    node* prev=NULL;
    node* n;
    while(curr!=NULL)
    {
        n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
    }
    head=prev;
    return;
}

//gfg's method
node* rec_gfg(node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node* r=rec_gfg(head->next);
    head->next->next=head;
    head->next=NULL;
    return r;
}
// mihir's method
void recursive_reverse(node* &head,node* &prev,node* &fin,int x,int t)
{
    if(t-1==x)
    {
        head->next=prev;
        fin=head;
        return;
    }
    else
    {
        recursive_reverse(head->next,head,fin,x+1,t);
        //cout<<fin->data<<" ";
        head->next=prev;
    }
}

int main()
{
    node* head=NULL;
    //buildll(head);
    intail(head,1);
    intail(head,2);
    intail(head,3);
    intail(head,4);
    intail(head,5);
    prn(head);
    node* prev=NULL;
    //cout<<"ee\n";
    node* temp=head;
    head=rec_gfg(head);
    prn(head);
}
