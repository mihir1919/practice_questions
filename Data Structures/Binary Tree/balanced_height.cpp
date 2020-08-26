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


//8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

int c(node* root)
{
    if(root==NULL)
    {
        return -1;
    }
    return 1+max(c(root->left),c(root->right));
}

bool hbal(node* root)
{
    if(root==NULL)
    {
        return true;
    }
    cout<<root->data<<" "<<abs(c(root->left)-c(root->right))<<"\n";
    if(abs(c(root->left)-c(root->right))<=1)
    {

        return (hbal(root->left))&&(hbal(root->right));

    }
    else
    {
        return false;
    }
}

class HBR
{
public:
    int h;
    bool balanced;
};

HBR im_bal(node* root)
{
    HBR p;
    if(root==NULL)
    {
        p.h=0;
        p.balanced=true;
        return p;
    }
    HBR l=im_bal(root->left);
    HBR r=im_bal(root->right);
    p.h=max(l.h,r.h)+1;
    if(abs(l.h-r.h)<=1 && l.balanced && r.balanced)
    {
        p.balanced=true;
    }
    else
    {
        p.balanced=false;
    }
    return p;
}

int main()
{
    node* root=build();
    prn(root);
    cout<<"\n";
    bool t=true;
    cout<<im_bal(root).h<<" "<<im_bal(root).balanced<<"\n";
}
