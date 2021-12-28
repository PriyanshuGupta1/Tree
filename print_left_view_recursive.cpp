//Printing left view of a binary tree using recursive method
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
int prev_level=0;//Global variable for storing the previous level
void print_left_view(node *root,int curr_level)//recursive solution
{
    if(root==NULL) 
        return;
    if(curr_level>prev_level)
    {
        cout<<root->value<<" ";//If new level is reached we are printing the left most value 
        prev_level=curr_level;
    }
    print_left_view(root->left,curr_level+1);
    print_left_view(root->right,curr_level+1);
}
int main()
{
    node *root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    print_left_view(root,1);
    return 0;
}