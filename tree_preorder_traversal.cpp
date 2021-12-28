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
//recursion solution of preorder traversal
void preorder_traversal(node *root)
{
    if(root == NULL)
        return;
    cout<<root->value<<" "; //visiting the root
    preorder_traversal(root->left);//traversing the left child
    preorder_traversal(root->right);//traversing the right child 
}
int main()
{
    node *root = new node(10);
    root->right = new node(20);
    root->left = new node(30);
    preorder_traversal(root);
    return 0;
}