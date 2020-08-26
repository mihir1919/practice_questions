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


void prn(node* root)
{
    if(root==NULL)
    {
        return;
    }
    deque<node*> v;
    v.push_back(root);
    v.push_back(NULL);
    while(!v.empty())
    {
        if(v.front()==NULL)
        {
            cout<<"\n";
            v.pop_front();
            if(v.empty())
            {
                break;
            }
            else
            {
                v.push_back(NULL);
            }
        }
        else
        {
            cout<<v.front()->data<<" ";
            node* x=v.front();
            v.pop_front();
            if(x->left!=NULL)
            {
                v.push_back(x->left);
            }
            if(x->right!=NULL)
            {
                v.push_back(x->right);
            }
        }
    }
}
node* build_bal(int arr[],int s,int e)
{
    if(s>e)
    {
        return NULL;
    }
    int mid=(s+e)/2;
    node* root=new node(arr[mid]);
    root->left=build_bal(arr,s,mid-1);
    root->right=build_bal(arr,mid+1,e);
    return root;
}
int main()
{
    int arr[7]={1,2,3,4,5,6,7};
    node* root=build_bal(arr,0,6);
    prn(root);
}
