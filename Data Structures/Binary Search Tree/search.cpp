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

bool search_node(node* root,int d)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==d)
    {
        return true;
    }
    if(root->data>d)
    {
        return search_node(root->left,d);
    }
    else
    {
        return search_node(root->right,d);
    }
}

int main()
{
    node* root=build();
    bf(root);
    cout<<search_node(root,0);
}

// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
// 8 10 1 6 8 9 7 -1
