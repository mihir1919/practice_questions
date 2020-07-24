#include<bits/stdc++.h>
using namespace std;
#include "fn.h"


int mid(node* s,node* f)
{
    if(f==NULL || f->next==NULL)
    {
        return s->data;
    }
    mid(s->next,f->next->next);
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
    cout<<mid(head,head);
}
