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
int i=0;
node* build(vector<int> pre,vector<int> ino,int s,int e)
{
    if(s>e)
    {
        return NULL;
    }
    node* root=new node(pre[i]);
    int x=find(ino.begin()+s,ino.begin()+e,pre[i++])-ino.begin();
    if(x>e)
    {
        return NULL;
    }

    root->left=build(pre,ino,s,x-1);
    root->right=build(pre,ino,x+1,e);
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

void preorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    vector<int> pre={5,3,1,7,6,8};
    vector<int> ino(pre.begin(),pre.end());
    sort(ino.begin(),ino.end());
    node* root=build(pre,ino,0,pre.size()-1);
    preorder(root);
}

// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

