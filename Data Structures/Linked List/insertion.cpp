
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

//functions to insert,delete,find linked list

// we use &head to reflect changes in the main function
void inshead(node* &head,int data)
{
    node* temp=new node(data);
    //temp->data=data;
    temp->next=head;
    head=temp;
}

void intail(node* &head,int data)
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
    else
    {
        node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        node* temp2=new node(data);
        temp->next=temp2;
        return;
    }
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

int len(node* head)
{
    int h=0;
    while(head!=NULL)
    {
        h++;
        head=head->next;
    }
    return h;
}

void inpos(node* &head,int data,int pos)
{
    int l=len(head);
    if(pos>=l || head==NULL)
    {
        intail(head,data);
    }
    else if(pos==0 || head==NULL)
    {
        inshead(head,data);
    }
    else
    {
        node* hea=head;
        pos--;
        while(pos--)
        {
            hea=hea->next;
        }
        node* temp=new node(data);
        temp->next=hea->next;
        hea->next=temp;
    }
    return;
}

void prn(node* head)
{
    if(head==NULL)
    {
        cout<<"\n";
        return;
    }
    cout<<head->data<<" ";
    prn(head->next);
}

void deletion(node* &head,int pos)
{
    node* h=head;
    pos--;
    if(h==NULL)
    {
        return;
    }
    while(h->next!=NULL && pos>0)
    {
        h=h->next;
        pos--;
    }
    if(pos<=0)
    {
        node* temp=h->next;
        free(h);
        h=temp;
        return;
    }
}

int searchll(int i,int j,node* head)
{
    if(head==NULL)
    {
        return -1;
    }
    if(head->data==j)
    {
        return i;
    }
    return (searchll(i+1,j,head->next));
}


void buildll(node* head)
{
    int n;
    cin>>n;
    while(n!=-1)
    {
        intail(head,n);
        cin>>n;
    }
    return;
}

int main()
{
    node* head = NULL;
    inshead(head,5);

    inshead(head,3);

    inshead(head,5);

    inshead(head,2);

    inshead(head,9);

    inshead(head,1);

    intail(head,77);

   // insmiddle(head,131,head);
    inpos(head,123,3);
    prn(head);
    deletion(head,3);
    prn(head);
//    cout<<searchll(0,123,head)<<"\n";
//    buildll(head);
//    prn(head);
}
