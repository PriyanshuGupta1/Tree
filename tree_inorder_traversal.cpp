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
//recursion solution of inorder traversal
void inorder_traversal(node *root)
{
    if(root == NULL)
        return;
    inorder_traversal(root->left);//traversing the left child
    cout<<root->value<<" "; //visiting the root
    inorder_traversal(root->right);//traversing the right child 
}
int main()
{
    node *root = new node(10);
    root->right = new node(20);
    root->left = new node(30);
    inorder_traversal(root);
    return 0;
}