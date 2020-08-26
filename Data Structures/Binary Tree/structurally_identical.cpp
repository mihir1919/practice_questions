#include<bits/stdc++.h>
using namespace std;

class node{
	public:
		string data;
		node* left;
		node* right;
	node(string d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};

node* build()
{
	string s;
	cin>>s;
	if(s=="false")
	{
		return NULL;
	}
	else if(s=="true")
    {
        cin>>s;
        node* root=new node(s);
		root->left=build();
		root->right=build();
		return root;
    }
	else
	{
		node* root=new node(s);
		root->left=build();
		root->right=build();
		return root;
	}
}

bool compare(node* root1,node* root2)
{
    if(root1==NULL && root2==NULL)
    {
        return true;
    }
	else if(root1==NULL && root2!=NULL)
	{
		return false;
	}
	else if(root1!=NULL && root2==NULL)
	{
		return false;
	}
	bool l=compare(root1->left,root2->left);
	bool r=compare(root1->right,root2->right);
	return l&&r;
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

int main() {
	node* root1=build();
	cout<<"\n";
	node* root2=build();
	bf(root1);
	bf(root2);
	cout<<compare(root1,root2);
	return 0;
}
//10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
//10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false 99 false false
