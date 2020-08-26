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

int sum_of_all_nodes(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return root->data+(sum_of_all_nodes(root->left)+sum_of_all_nodes(root->right));
}

int count_roots(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+(count_roots(root->left)+count_roots(root->right));
}

int main()
{
    node* root=buildTree();
    cout<<sum_of_all_nodes(root);
    // 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

}

