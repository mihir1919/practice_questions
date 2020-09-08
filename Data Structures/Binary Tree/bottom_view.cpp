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
    node* root=new node(d);
    node* t=NULL;
    deque<node*> q;
    q.push_back(root);
    q.push_back(t);
    int n,m;
    while(!q.empty())
    {
        if(q.front()==t)
        {
            q.pop_front();
            if(q.empty())
            {
                break;
            }
            else
            {
                q.push_back(t);
            }
        }
        node* x=q.front();
        q.pop_front();
        cin>>n>>m;
        node* l=NULL;
        node* r=NULL;
        if(n!=-1)
        {
            l=new node(n);
            q.push_back(l);
        }
        if(m!=-1)
        {
            r=new node(m);
            q.push_back(r);
        }
        x->left=l;
        x->right=r;
    }
    return root;
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


map<int,int> mapp;
void hm(node* root,int k)
{
    if(root==NULL)
    {
        return;
    }
    mapp[k]=root->data;
    hm(root->left,k-1);
    hm(root->right,k+1);
}

int main()
{
    node* root=buildTree();
    hm(root,0);
    for(auto x:mapp)
    {
        cout<<x.second<<" ";
    }
}
