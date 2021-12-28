# structure of Tree

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
}