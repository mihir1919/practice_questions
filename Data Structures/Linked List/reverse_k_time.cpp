#include<bits/stdc++.h>
using namespace std;

class node{
	public:
	int data;
	node* next;
};

void prn(node* h)
{
	if(h==NULL)
	{
	    cout<<"\n";
		return;
	}
	cout<<h->data<<" ";
	prn(h->next);
}

node* reverse_ll(node* head)
{
	if(head->next==NULL)
	{
		return head;
	}
	node* c=reverse_ll(head->next);
	head->next->next=head;
	head->next=NULL;
	return c;
}

int main()
{
	node* ab=NULL;
	node* ba=ab;
	node* head=new node;
	int i,j,k,n,m;
	cin>>n>>k;
	head=NULL;
	node* h=head;
	for(i=0;i<n/3;i++)
	{
		//head=NULL;
		h=NULL;
		for(j=0;j<3;j++)
		{
			node* t=new node;
			cin>>m;
			t->data=m;
			t->next=NULL;
			if(h==NULL)
			{
				h=t;
				head=t;
			}
			else
			{
				h->next=t;
				h=t;
			}
		}
		node* c=reverse_ll(head);
		if(ab==NULL)
		{
			ab=c;
		}
		else
		{
			ba->next=c;
		}
		ba=head;
	}
	prn(ab);
	return 0;
}
