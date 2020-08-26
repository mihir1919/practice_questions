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

int i=0;

node* build(vector<int> arr1,vector<int> arr2,int s,int e)
{
    if(s>e)
    {
        return NULL;
    }
    node* root=new node(arr1[i]);
    int x=find(arr2.begin()+s,arr2.begin()+e,arr1[i++])-arr2.begin();
    if(x>e)
    {
        return NULL;
    }
    root->left=(build(arr1,arr2,s,x-1));
    root->right=(build(arr1,arr2,x+1,e));
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

int main()
{
    vector<int>arr1={1,2,3,4,8,5,6,7};
    vector<int>arr2={3,2,8,4,1,6,7,5};
    node* root=build(arr1,arr2,0,arr1.size()-1);
    bf(root);
}
