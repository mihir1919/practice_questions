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

int c=0;

void intail(node* &head,int data)
{
	node* t=new node(data);
	if(head==NULL)
	{
		head=t;
	}
	else
	{
		node* h=head;
		while(h->next!=NULL)
		{
			h=h->next;
		}
		h->next=t;
	}
}

node* build(node* &head)
{
	int n;
	cin>>n;
	while(n!=-1)
	{
		intail(head,n);
		cin>>n;
		c++;
	}
	return head;
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

node* from_last(node* head,int k)
{
	node* h=head;
	node* f=head;
	while(k--)
	{
		if(f==NULL || f->next==NULL)
		{
			return f;
		}
		f=f->next;
	}
	while(f!=NULL)
	{
		f=f->next;
		h=h->next;
	}
	return h;
}

int main()
{
	int i,j,k,n,m;
	node* head=NULL;
	head=build(head);
	cin>>(k);
	k=k%c;
	if(k==0)
	{
		cout<<head->data<<"\n";
		return 0;
	}
	cout<<from_last(head,k)->data<<endl;
}
