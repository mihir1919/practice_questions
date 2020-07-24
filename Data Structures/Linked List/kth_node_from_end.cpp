#include<bits/stdc++.h>
using namespace std;
#include "fn.h"


void kth(node* head,int k)
{
    static int x=0;
    if(head==NULL)
    {
        return;
    }
    kth(head->next,k);
    if(++x==k)
    {
        cout<<head->data;return;
    }
    return;
}
//runner technique
void kth_runner(node* head,int k)
{
    node* f=head;
    node* s=head;
    while(k--)
    {
        f=f->next;
    }
    while(f!=NULL)
    {
        f=f->next;
        s=s->next;
    }
    cout<<s->data<<"\n";
}

int main()
{
    node* head=NULL;
    //buildll(head);
    intail(head,1);
    intail(head,2);
    intail(head,3);
    intail(head,4);
    //intail(head,5);
    prn(head);
    kth_runner(head,2);
}
