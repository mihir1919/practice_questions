
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
node* merge(node* head,node* a,node* b)
{
	if(head==NULL)
	{
		if(a==NULL)
		{
			return b;
		}
		else if(b==NULL)
		{
			return a;
		}
		else
		{
			node* h=b;
			while(h!=NULL && h->next!=NULL)
			{
				h=h->next;
			}
			h->next=a;
			//prn(a);
			return b;
		}
	}
	//node* c;
	if(head->data%2==0)
	{
		intail(a,head->data);
	}
	else
	{
		intail(b,head->data);
	}
	return merge(head->next,a,b);
}


int main()
{
    int i,j,k,t,n;
		node* head = NULL;
		cin>>n;
		while(n--)
		{
			cin>>k;
			intail(head,k);
		}
		node* a=NULL;
		node* b=NULL;
		node* x=merge(head,a,b);
		prn(x);
}
