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

node* buildTree()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    else
    {
        node* root=new node(d);
        root->left=buildTree();
        root->right=buildTree();
        return root;
    }
}



void printpre(node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    printpre(root->left);
    printpre(root->right);
}



void printinorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    printinorder(root->left);
    cout<<root->data<<" ";
    printinorder(root->right);
}
// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1


void printpost(node* root)
{
    if(root==NULL)
    {
        return;
    }
    printpost(root->left);
    printpost(root->right);
    cout<<root->data<<" ";
}

int height(node* root)
{
    if(root==NULL)
    {
        return -1;
    }
    return 1+(max(height(root->left),height(root->right)));
}

void levelorder(node* root,int h,int k,int e)
{
    if(k>h || root==NULL)
    {
        return;
    }
    if(e==k)
    {
        cout<<"k is "<<k<<" "<<root->data<<"\n";
        return levelorder(root,h,k+1,0);
    }
    else if(e<k)
    {
        levelorder(root->left,h,k,e+1);
        levelorder(root->right,h,k,e+1);
    }
    else
    {
        return;
    }
    return;
}

void prn(node* root,int k)
{
    if(root==NULL)
    {
        return;
    }
    if(k==0)
    {
        cout<<root->data<<" ";
    }
    else if(k>0)
    {
        prn(root->left,k-1);
        prn(root->right,k-1);
    }
    return;
}

void pn(node* root,int h,int i)
{
    if(i>h)
    {
        return;
    }
    prn(root,i);
    pn(root,h,i+1);
}

int main()
{
    node* root=buildTree();
    //printpre(root);
    //cout<<"\n";
    //levelorder(root,height(root),0,0);
    pn(root,height(root),0);
}
