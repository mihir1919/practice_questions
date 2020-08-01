//#include<bits/stdc++.h>
//using namespace std;
//
//class node{
//public:
//    int data;
//    node* next;
//
//    node(int d)
//    {
//        data=d;
//        next=NULL;
//    }
//} ;
//
//void cinhead(node* &head,int d)
//{
//    node* t=new node(d);
//    t->next=head;
//    if(head==NULL)
//    {
//        head=t;
//        head->next=head;
//    }
//    else
//    {
//        t->next=head;
//        node* h=head;
//        while(h->next!=head)
//        {
//            h=h->next;
//        }
//        h->next=t;
//        t=head;
//    }
//}
//
//
//void cintail(node* &head,int d)
//{
//    node* t=new node(d);
//    t->next=head;
//    node* h=head;
//    if(head==NULL)
//    {
//        head=t;
//        head->next=head;
//    }
//    else
//    {
//        node* h=head;
//        while(h->next!=head)
//        {
//            h=h->next;
//        }
//        h->next=t;
//        t->next=head;
//    }
//}
//
//void prn(node* head,node* h)
//{
//    if(head==NULL)
//    {
//        return;
//    }
//    if(h->next==head)
//    {
//        cout<<h->data<<"\n";
//        return;
//    }
//    cout<<h->data<<" ";
//    prn(head,h->next);
//}
//
//void delete_node (node* &head,node* &h,int pos)
//{
//    if(head==NULL)
//    {
//        return;
//    }
//    if(pos-1<=0)
//    {
//        if(h==head)
//        {
//            node* temp=head;
//            while(temp->next!=head)
//            {
//                temp=temp->next;
//            }
//            temp->next=head->next;
//            head=head->next;
//        }
//        else if(h->next==head)
//        {
//            node* temp=head;
//            while(temp->next->next!=head)
//            {
//                temp=temp->next;
//            }
//            delete(temp->next);
//            temp->next=head;
//        }
//        else
//        {
//            node* temp=h->next->next;
//            delete(h->next);
//            h->next=temp;
//        }
//        return;
//    }
//    delete_node(head,h->next,pos-1);
//}
//
//int main()
//{
//    int i,j,k,n,m;
//    node* head=NULL;
//    cinhead(head,1);
//    cinhead(head,2);cinhead(head,3);
//    cinhead(head,4);
//    cintail(head,5);
//    cintail(head,6);
//    cintail(head,7);
//    cintail(head,8);
//    delete_node(head,head,1);
//    prn(head,head);
//}

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

void prn(node* h,node* head)
{
	if(head==NULL)
	{
		return;
	}
	if(h->next=head)
	{
		cout<<h->data<<"\n";
		return;
	}
	cout<<h->data<<" ";
	prn(h->next,head);

}

void intail(node* &head,int d)
{
    //prn(head,head);
    node* t=new node(d);
    t->next=head;
    node* h=head;
    if(head==NULL)
    {
        head=t;
        head->next=head;
    }
    else
    {
        node* h=head;
        while(h->next!=head)
        {
            h=h->next;
        }
        h->next=t;
        t->next=head;
    }

}

node* build(node* &head)
{
	int n;
	cin>>n;
	while(n!=-1){
		intail(head,n);
		cin>>n;
	}
	return head;
}



int main() {
	node* head=NULL;
	build(head);
	prn(head,head);
	return 0;
}
