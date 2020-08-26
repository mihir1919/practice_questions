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

node* build()
{
    int n;
    cin>>n;
    if(n==-1)
    {
        return NULL;
    }
    else
    {
        node* root=new node(n);
        root->left=build();
        root->right=build();
        return root;
    }
}

void prn(node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    prn(root->left);
    prn(root->right);
}

int sum_of_child(node* root)
{
    int x=0;
    if(root->left!=NULL)
    {
        x+=root->left->data+sum_of_child(root->left);
    }
    if(root->right!=NULL)
    {
        x+=root->right->data+sum_of_child(root->right);
    }
    return x;
}

int sum_rep(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return root->data;
    }
    int x=root->data;
    root->data=sum_rep(root->left)+sum_rep(root->right);
    return x+root->data;
}
//8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

int main()
{
    node* root=build();
    prn(root);
    cout<<"\n";
    sum_rep(root);
    prn(root);
}
