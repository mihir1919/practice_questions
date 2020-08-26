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

void bfs(node* root)
{
    deque<node*> q;
    q.push_back(root);
    while(!q.empty())
    {
        node* x=q.front();
        cout<<x->data<<" ";
        q.pop_front();
        if(x!=NULL && x->left!=NULL)
        {
            q.push_back(x->left);
        }
        if(x!=NULL && x->right!=NULL)
        {
            q.push_back(x->right);
        }
    }
}
//with new line after every kth row
void bfs_break(node* root)
{
    deque<pair<node*,int>> q;
    pair<node*,int> temp;
    temp.first=root;
    temp.second=0;
    pair<node*,int> ntemp;
    ntemp.first=NULL;
    ntemp.second=0;
    q.push_back(temp);
    q.push_back(ntemp);
    int t=0;
    while(!q.empty())
    {
        if(q.front()==ntemp)
        {
            break;
        }
        pair<node*,int> p=q.front();
        node* x=p.first;
        int k=p.second;
        q.pop_front();
        cout<<x->data<<" ";
        //cout<<"\n k and t is "<<k<<" "<<t<<" \n";

        if(x!=NULL && x->left!=NULL)
        {
            q.push_back(make_pair(x->left,k+1));
        }
        if(x!=NULL && x->right!=NULL)
        {
            q.push_back(make_pair(x->right,k+1));
        }
        if(q.front()==ntemp)
        {
                cout<<"\n";
                q.pop_front();
                q.push_back(ntemp);
        }
    }
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
    node* root=buildTree();
    //printpre(root);
    //cout<<"\n";
    //levelorder(root,height(root),0,0);
    bf(root);
}

