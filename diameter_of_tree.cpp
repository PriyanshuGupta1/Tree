//here for calculation of diameter of tree the total number of nodes in the path is being calculated
// if the question requires the no of edges instead of nodes use diameter=max(diameter,lh+rh);
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
        left = right= NULL;
    }
};
int diameter=0;
int diamater_of_tree(node *root)
{
    if(root==NULL) 
        return 0;
    int lh=diamater_of_tree(root->left);
    int rh=diamater_of_tree(root->right);
    diameter=max(diameter,lh+rh+1);
    return max(lh, rh)+1;    
}
int main()
{
    node *root=new node(10);
	root->left=new node(20);
	root->right=new node(30);
	root->right->left=new node(40);
	root->right->right=new node(60);
	root->right->left->left=new node(50);
	root->right->right->right=new node(70);
	cout<<"Height: "<<diamater_of_tree(root)<<endl;
	cout<<"Diameter: "<<diameter<<endl;
    return 0;
}