#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node* next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

//class LinkedList{
//    node* head;
//    node* tail;
//public:
//    LinkedList()
//    {
//        head=NULL;
//        tail=NULL;
//    }
//    void Insert()
//    {
//
//    }
//};

// we use &head to reflect changes in the main function
void inshead(node* &head,int data)
{
    node* temp=new node(data);
    //temp->data=data;
    temp->next=head;
    head=temp;
}

void intail(node* head,int data)
{
    if(head==NULL || head->next==NULL)
    {
        node* temp=new node(data);
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            head->next=temp;
        }
        return;
    }
    intail(head->next,data);
}

void insmiddle(node* &head,int data,node* f)
{
    if(head==NULL)
    {
        inshead(head,data);
        return;
    }
    else if(f==NULL || f->next==NULL || f->next->next==NULL)
    {
        node* temp=new node(data);
        temp->next=head->next;head->next=temp;
        return;
    }
    head=head->next;
    f=(f->next)->next;
    insmiddle(head,data,f);
}
void prn(node* head)
{
    if(head==NULL)
    {
        return;
    }
    cout<<head->data<<" ";
    prn(head->next);
}

int main()
{
    node* head = NULL;
    inshead(head,5);
    inshead(head,3);inshead(head,5);
    inshead(head,2);
    inshead(head,9);
    inshead(head,1);
    intail(head,77);
    intail(head,77);intail(head,77);intail(head,77);intail(head,77);
    insmiddle(head,131,head);
    prn(head);
}
