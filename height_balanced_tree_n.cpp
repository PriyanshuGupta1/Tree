// height balancing is where the difference in height of right subtree and left subtree is almost 1
// TOC: O(n)
// SC: O(n)
#include <iostream>
using namespace std;
struct node 
{
    int value;
    node *left;
    node *right;
    node(int x)
    {
        value = x;
        left=right=NULL;
    }
};
int height_balance(node *root)
{
    if(root==NULL) return 0;
    int lh=height_balance(root->left);
    if(lh==-1) return -1;
    int rh=height_balance(root->right);
    if(rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;
    else 
        return max(lh, rh)+1;
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
    return 0;
}