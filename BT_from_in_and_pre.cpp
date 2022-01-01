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
        left = right=NULL;
    }
};
int last_index=0;
node* creation(int pre[],int in[],int n,int starting,int ending)
{
    if(starting>ending)return NULL;
    node *root=new node(pre[last_index++]);
    int root_in;
    for(int i=starting;i<=ending;i++)
    {
        if(in[i]==root->value)
        {
            root_in=i;
            break;
        }
    }
    root->left=creation(pre,in,n,starting,root_in-1);
    root->right=creation(pre,in,n,root_in+1,ending);
    return root;
}
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
    int pre[]={10,20,30,40,50},in[]={20,10,40,30,50},n=5;
    node *root=creation(pre,in,n,0,n-1);
    inorder_traversal(root);
    return 0;
}