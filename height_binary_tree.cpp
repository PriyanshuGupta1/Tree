#include <iostream>
using namespace std;
struct node 
{
    int value;
    node *left;
    node *right;
    node (int x)
    {
        value = x;
        left=right=NULL;
    }
};
int height(node *root)
{
    if(root == NULL) 
        return 0;
    else return max(height(root->left), height(root->right))+1;
}
int main()
{
    node *root = new node(10);
    root->left = new node(20);
    root->right=new node(30);
    root->right->left = new node(123);
    root->right->left->right = new node(12);
    cout<<"The maximum height of the binary tree is "<<height(root)<<endl;
    return 0;
}
