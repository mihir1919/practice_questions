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

bool fn(node* root,int mi,int ma)
    {
        if(root==NULL)
        {
            return true;
        }
        if(root->data>=ma || root->data<=mi)
        {
            return false;
        }
        bool l=fn(root->left,mi,root->data);
        bool r=fn(root->right,root->data,ma);
        return l&&r;
    }
bool checkBST(node* root) {
    return fn(root,-99999,99999);
}

int main()
{
    node* root=build();
    cout<<checkBST(root);
    //bf(root);
}

// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

