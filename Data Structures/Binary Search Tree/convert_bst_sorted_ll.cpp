#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }

};

node* insert_node(node* &root,int d)
{
    if(root==NULL)
    {
        return new node(d);
    }
    //recursive
    if(root->data>=d)
    {
        root->left=insert_node(root->left,d);
    }
    else
    {
        root->right=insert_node(root->right,d);
    }
    return root;
}

node* build()
{
    int d;
    cin>>d;
    node* root=NULL;
    while(d!=-1)
    {
        root=insert_node(root,d);
        cin>>d;
    }
    return root;
}

pair<node*,node*> toLL(node* root)
{
    pair<node*,node*> p;
    p.first=root;
    p.second=root;
    if(root==NULL)
    {
        p.first=p.second=NULL;
        return p;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return p;
    }

    pair<node*,node*> l=toLL(root->left);
    pair<node*,node*> r=toLL(root->right);
    if(l.first!=NULL)
    {
        p.first=l.first;
        l.second->right=root;
    }
    if(r.first!=NULL)
    {
        root->right=r.first;
        p.second=r.second;
    }ss
    return p;
}

void prn_ll(node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    prn_ll(root->right);
}

int main()
{
    node* root=build();
    pair<node*,node*> p=toLL(root);
    //cout<<p.first->data<<" "<<p.second->data<<" ";
    cout<<endl;
    prn_ll(p.first);
    //bf(root);
}

// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
// 5 3 8 2 4 7 15 -1

