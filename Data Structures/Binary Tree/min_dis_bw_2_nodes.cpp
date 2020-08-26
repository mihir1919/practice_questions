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

int h_w_data(node* root,int a,int level)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->data==a)
    {
        return level;
    }
    int l=h_w_data(root->left,a,level+1);
    int r=h_w_data(root->right,a,level+1);
    return max(l,r);
}

node* lca(node* root,int a,int b)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==a || root->data==b)
    {
        return root;
    }
    node* l=lca(root->left,a,b);
    node* r=lca(root->right,a,b);
    if(l!=NULL && r!=NULL)
    {
        return root;
    }
    if(l!=NULL)
    {
        return l;
    }
    return r;
}

int min_dis(node* root,int a,int b)
{
    node* t=lca(root,a,b);
    int ah=h_w_data(t,a,0);
    int bh=h_w_data(t,b,0);
    return (ah+bh);
}

int main()
{
    node* root=buildTree();
    bf(root);
    cout<<min_dis(root,14,7);
}
//8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
