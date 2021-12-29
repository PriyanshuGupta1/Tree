//Tree is following children sum property or not where sum of childrens is equal to parent 
//Space complexity :O(n) or O(h) [where h is height of binary tree]
//Time complexity: O(n)
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
bool children_sum_property(node *root)
{
    if(root==NULL) return true;
    if(root->left!=NULL && root->right!=NULL)
    {
        if((root->left->value+root->right->value)!=root->value)
        {
            return false;
        }
    }
    else if(root->left!=NULL && root->right==NULL)
    {
        if(root->left->value!=root->value)
            return false;
    }
    else if(root->left==NULL && root->right!=NULL)
    {
        if(root->right->value!=root->value)
            return false;
    }
    else
        return true;
    return children_sum_property(root->left) && children_sum_property(root->right);
}
int main()
{
    node *root=new node(20);
    root->left=new node(8);
    root->right=new node(12);
    root->left->left=new node(3);
    root->left->right=new node(5);
    if(children_sum_property(root)==1)
        cout<<"It follows children_sum_property"<<endl;
    else
        cout<<"It does not follow children_sum_property"<<endl;
    node *root1=new node(3);
    root1->left=new node(1);
    root1->right=new node(2);
    root1->right->left=new node(1);
    root1->right->right=new node(2);
    if(children_sum_property(root1)==1)
        cout<<"It follows children_sum_property"<<endl;
    else
        cout<<"It does not follow children_sum_property"<<endl;
    return 0;
}