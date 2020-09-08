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

void bfs(node* root)
{
	deque<node*> q;
	q.push_back(root);
	node* t=NULL;
	q.push_back(t);
	int k=0;
	vector<string> v;
	while(!q.empty())
	{
		if(q.front()==t)
		{
			if(k==1)
			{
				reverse(v.begin(),v.end());
			}
			for(auto x:v)
			{
				cout<<x<<" ";
			}
			v.clear();
			q.pop_front();
			if(q.empty())
			{
				break;
			}
			else
			{
				q.push_back(t);
			}
			k=k==1?0:1;
		}
		node* x=q.front();
		q.pop_front();
		v.push_back(x->data);
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
	bfs(root1);
	return 0;
}
