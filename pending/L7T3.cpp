#include<bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    node *left;
    node *right;
    node *parent;
};

node* create_node(int item)
{
    node *new_node=new node();
    if(new_node==NULL)
        cout<<"Error"<<endl;
    else
    {
        new_node->value=item;
        new_node->left=NULL;
        new_node->right=NULL;
        new_node->parent=NULL;
    }
    return new_node;
}


node* Tree_insert(struct node* x, int key)
{
    if (x == NULL) return create_node(key);

    if (key < x->value)
        x->left  = Tree_insert(x->left, key);
    else if (key > x->value)
        x->right = Tree_insert(x->right, key);

    return x;
}


int Tree_height(node* x)
{
    int lh=-1;
    int rh=-1;
    if (x == NULL)
        return -1;
    else
    {
        lh = Tree_height(x->left);
        rh = Tree_height(x->right);

        return 1+max(lh,rh);
    }
}


void printLevel(node* x,int level)
{
    if(x==NULL)
        return;
    if(level==1)
        cout<<x->value<<" ";
    else if(level>1)
    {
        printLevel(x->left,level-1);
        printLevel(x->right,level-1);
    }
    else if(level<1)
        return printLevel(x,level-1);
}

void printLevelOrder(node* x)
{
    int h=Tree_height(x);
    for(int i=1; i<=h; i++)
        printLevel(x,i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int v,n,i;
    node *root;
    root=NULL;

    while(1)
    {
        cin>>v;
        if(v==-1) break;
        root=Tree_insert(root,v);
    }
    cout<<Tree_height(root)<<endl;
}
