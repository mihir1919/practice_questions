#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* right;
    node* left;

    node(int d)
    {
        data=d;
        right=NULL;
        left=NULL;
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

int height(node* root)
{
    if(root==NULL)
    {
        return -1;
    }
    return 1+(max(height(root->left),height(root->right)));
}

int diameter(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    node* l=root->left;
    node* r=root->right;
    int ro=2+(height(l)+height(r));
    int le=diameter(root->left);
    int ri=diameter(root->right);
    return max(max(ro,le),ri);
}

int count_node(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+(count_node(root->left)+count_node(root->right));
}

pair<int,int> fast_d(node* root)
{
    pair<int,int> p;
    if(root==NULL)
    {
        p.first=0;
        p.second=0;
        return p;
    }
    else
    {
        pair<int,int> ld=fast_d(root->left);
        pair<int,int> rd=fast_d(root->right);

        p.first=max(ld.first,rd.first)+1;
        p.second=max(ld.first+rd.first,max(ld.second,rd.second));
        return p;
    }
}

int main()
{
    node* root=build();
    int n=count_node(root);
    cout<<fast_d(root).second;
}
// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
