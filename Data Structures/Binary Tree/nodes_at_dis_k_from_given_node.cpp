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


// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

void bf(node* root)
{
    deque<node*> q;
    q.push_back(root);
    q.push_back(NULL);
    while(!q.empty())
    {
        if(q.front()==NULL)
        {
            cout<<"\n";
            q.pop_front();
            if(q.empty())
            {
                break;
            }
            else
            {
                q.push_back(NULL);
            }
        }
        cout<<q.front()->data<<" ";
        node* x=q.front();
        q.pop_front();
        if(x->left!=NULL)
        {
            q.push_back(x->left);
        }
        if(x->right!=NULL)
        {
            q.push_back(x->right);
        }
    }
}

int h(node* root)
{
    if(root==NULL)
    {
        return -1;
    }
    return 1+(max(h(root->left),h(root->right)));
}

void node_up(node* root,node* ac,int k)
{
    if(root==ac)
    {
        return;
    }
    if(k==0)
    {
        cout<<root->data<<" ";
        return;
    }
    node_up(root->left,ac,k-1);
    node_up(root->right,ac,k-1);
}

void dis_k(node* root,int k)
{
    if(root==NULL)
    {
        return;
    }
    if(k==0)
    {
        cout<<root->data<<" ";
    }
    dis_k(root->left,k-1);
    dis_k(root->right,k-1);
}

int kn(node* target,node* root,int k)
{
    if(root==NULL)
    {
        return -1;
    }
    if(target==root)
    {
        dis_k(root,k);
        return 0;
    }
    int x=kn(target,root->left,k);
    if(x!=-1)
    {
        int z=x+1;
        if(k-z<=0)
        {
            dis_k(target,0);
        }
        else
        {
            dis_k(root,(k-z));
        }
    }
    else
    {
        kn(target,root->right,k);
    }
}

int ans(node* root,node* target,int k)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root==target)
    {
        dis_k(root,k);
        return 0;
    }
    int l=ans(root->left,target,k);
    if(l!=-1)
    {
        if(abs(k-l)==1)
        {
            dis_k(root,0);
        }
        else
        {
            dis_k(root->right,abs(k-l-2));
        }
        return l+1;
    }
    int r=ans(root->right,target,k);
    if(r!=-1)
    {
        if(abs(k-r)==1)
        {
            dis_k(root,0);
        }
        else
        {
            dis_k(root->left,abs(k-r-2));
        }
        return r+1;
    }
    return -1;
}

int main()
{
    node* root=buildTree();
    node* target=root->left->left;
    ans(root,target,3);
}

//1 2 4 6 99 -1 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1

