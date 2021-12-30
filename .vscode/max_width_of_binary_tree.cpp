#include <iostream>
#include <queue>
using namespace std;
struct node
{
    int value;
    node *left;
    node *right;
    node(int x)
    {
        x=value;
        left=right=NULL;
    }
};
int max_width_of_binary_tree(node *root)
{
    if(root==NULL) return 0;
    queue <node *> q;
    q.push(root);
    int max_width=q.size();
    q.push(NULL);
    while(q.size()>1)
    {
        node *curr=q.front();
        q.pop();
        if(curr==NULL)
        {
            q.push(curr);
            int local_width=q.size()-1;
            if(local_width>max_width)
                max_width=local_width;
        }
        else
        {   
            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);
        }
    }
    return max_width;
}
int main()
{
    node *root=new node(10);
	root->left=new node(5);
	root->right=new node(30);
	root->right->left=new node(15);
	root->right->right=new node(20);
    root->left->right=new node(11);
    cout<<max_width_of_binary_tree(root)<<endl;
    return 0;
}