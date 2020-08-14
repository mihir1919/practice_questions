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
	}
};

void prn(node* h)
{
	if(h==NULL)
	{
		return;
	}
	if(h==NULL)
	{
		return;
	}
	cout<<h->data<<" ";
	prn(h->next);
}

void intail(node* &head,int d)
{
    //prn(head,head);
    node* t=new node(d);
    t->next=NULL;
    //node* h=head;
    if(head==NULL)
    {
        head=t;
        head->next=NULL;
    }
    else
    {
        node* h=head;
        while(h->next!=NULL)
        {
            h=h->next;
        }
        h->next=t;
        t->next=NULL;
    }

}

int len(node* head)
{
    if(head==NULL)
    {
        return 0;
    }
    return 1+(len(head->next));
}

insert_sort(node* &head)
{
	node* i=head;
	node* j=head;
	while(i!=NULL)
	{
		j=i->next;
		while(j!=NULL)
		{
			if(i->data>j->data)
			{
				int t=i->data;
				i->data=j->data;
				j->data=t;
			}
			j=j->next;
		}
		i=i->next;
	}
}


int main() {
	node* head=NULL;
	int i,j,k,n,m;
	cin>>n;
	while(n--)
	{
		cin>>m;
		intail(head,m);
	}
	insert_sort(head);
	prn(head);
	return 0;
}
