// height balancing is where the difference in height of right subtree and left subtree is almost 1
// TOC: O(n^2)
// SC:O(n)
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
        value=x;
        left=right=NULL;
    }
};
int height(node *root)
{
    if(root==NULL)
        return 0;
    else return max(height(root->left), height(root->right))+1;
}
bool height_balance(node *root)
{
    if(root==NULL) return true;
    queue <node *> a;
    a.push(root);
    while(a.empty()==false)
    {
        node *curr = a.front();
        a.pop();
        int t=height(root->left),b=height(root->right);
        if(abs(t-b)>1)
            return false;
        if(curr->left!=NULL) 
            a.push(curr->left);
        if(curr->right!=NULL) 
            a.push(curr->right);
    }
    return true;
}
int main()
{
    node *root=new node(10);
	root->left=new node(5);
	root->right=new node(30);
	root->right->left=new node(15);
	root->right->right=new node(20);
    cout<<height_balance(root)<<endl;
    node *root1=new node(3);
	root1->left=new node(4);
	root1->left->left=new node(5);
    cout<<height_balance(root1)<<endl;
    return 0;
}