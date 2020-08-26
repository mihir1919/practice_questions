#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

TreeNode* buildTree()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    else
    {
        TreeNode* root=new TreeNode(d);
        root->left=buildTree();
        root->right=buildTree();
        return root;
    }
}


// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

void bf(TreeNode* root)
{
    deque<TreeNode*> q;
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
        TreeNode* x=q.front();
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

int h(TreeNode* root)
{
    if(root==NULL)
    {
        return -1;
    }
    return 1+(max(h(root->left),h(root->right)));
}

pair<int,int> max_sum(TreeNode* root)
{
    pair<int,int> p;
    if(root==NULL)
    {
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int> l=max_sum(root->left);
    pair<int,int> r=max_sum(root->right);
    int op1=l.first+root->data;
    int op2=root->data+r.first;
    int op3=root->data;
    int op4=root->data+l.first+r.first;
    int sum_through_root=max(op1,max(op2,max(op3,op4)));
    p.first=max(l.first,max(r.first,0))+root->data;//branch sum
    p.second=max(l.second,max(r.second,sum_through_root));//max sum ie sum without root(left or right) or with root
    return p;
}

int main()
{
    TreeNode* root=buildTree();
    pair<int,int> p=max_sum(root);
    cout<<p.first<<" "<<p.second;
}

//8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
//-10 9 -1 -1 20 15 -1 -1 7 -1 -1


