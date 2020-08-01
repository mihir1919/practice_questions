// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/*You are required to complete this method */

Node* mid(Node* head)
{
    Node* h=head;
    Node* f=h->next;
    while(f!=NULL && f->next!=NULL)
    {
        f=f->next->next;
        h=h->next;
    }
    return h;
}
Node* reverse(Node* head)
{
    if(head->next==NULL)
    {
        return head;
    }
    Node* c=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return c;
}

bool isPalindrome(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node* m=mid(head);
    Node* b=m->next;
    m->next=NULL;
    b=reverse(b);
    bool f=true;
    while(head!=NULL && b!=NULL)
    {
        if(head->data!=b->data)
        {
            f=false;
            break;
        }
        head=head->next;
        b=b->next;
    }
    return f;
}

