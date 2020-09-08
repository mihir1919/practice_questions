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

node* insert_at_pos(node* &root,int x)
{
	if(root==NULL)
	{
		return new node(x);
	}
	if(root->data>x)
	{
		root->left=insert_at_pos(root->left,x);
	}
	else
	{
		root->right=insert_at_pos(root->right,x);
	}
	return root;
}

node* build(node* &root,vector<int> v,int s,int e)
{
	if(s>e)
	{
		return NULL;
	}
	int mid=(s+e)/2;
	//cout<<root->data<<" ";
	root=insert_at_pos(root,v[mid]);
	//cout<<root->data<<" ";
	build(root,v,s,mid-1);
	build(root,v,mid+1,e);
	return root;
}

void printpre(node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    printpre(root->left);
    printpre(root->right);
}

void fn(node* &root,int* s)
{
    if(root==NULL)
    {
        return;
    }
    fn(root->right,s);
    root->data+=*s;
    *s=root->data;
    fn(root->left,s);
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
	int i,j,k,n,m;
	cin>>n;
	vector<int> v(n,0);
	for(i=0;i<n;i++)
	{
		cin>>v[i];
	}
	node* root=NULL;
	root=build(root,v,0,v.size()-1);
	bf(root);
	int sum=0;
	int* s=&sum;
	fn(root,s);
	cout<<"\n";
	bf(root);
	return 0;
}
