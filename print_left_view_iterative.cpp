//Printing left view of a binary tree using iterative method
//Space complexity :O(n) or O(w) [where w is width of binary tree]
//Time complexity: O(n)
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
        value = x;
        left=right=NULL;
    }
};
void print_left_view(node *root)//iterative solution
{
    if(root==NULL) 
        return;
    queue <node *> q;
    q.push(root);
    while(q.empty()==false)
    {
        int size=q.size();
        for(int i=0; i<size; i++)
        {
            node *curr=q.front();
            q.pop();
            if(i==0)
                cout<<curr->value<<" ";
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
    }
}
int main()
{
    node *root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    print_left_view(root);
    return 0;
}