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


node* recursive_insert(node* x, int key)
{
    if (x == NULL) return create_node(key);

    if (key < x->value)
    {
        node * temp;
        temp = recursive_insert(x->left, key);
        x->left=temp;
        temp->parent=x;
    }
    else if (key > x->value)
    {
        node * temp;
        temp = recursive_insert(x->right, key);
        x->right=temp;
        temp->parent=x;
    }

    return x;
}


int Tree_height(node* x)
{
    int lh=-1;
    int rh=-1;
    if (x == NULL)
        return 0;
    else
    {
        lh = Tree_height(x->left);
        rh = Tree_height(x->right);

        return 1+max(lh,rh);
    }
}


int tree_size(node* x)
{
    if (x == NULL)
        return 0;
    else
        return(tree_size(x->left) + 1 + tree_size(x->right));
}





int nodes_with_lesser_value(node* root, node* x)
{
    node* org_root=root;
    node* org_x=x;
    int less_valued_nodes=0;
    if(x==root) less_valued_nodes=tree_size(root->left); //if node is root -> calc left subtree size
    else
    {
        if(x->value>root->value) //if node is greater than root calc left subtree size of root, add 1(as root is less than that node)
        {
            less_valued_nodes=tree_size(root->left)+1;
            less_valued_nodes=less_valued_nodes+tree_size(x->left); //also calculate it's left subtree size if it has any
        }
        else if(x->value<root->value) //if node is less than root, only calc the left subtree size
            less_valued_nodes=less_valued_nodes+tree_size(x->left);
        node* p=new node();
        p=x->parent;
        if(x->value<p->value && x->left==NULL) // if node is the left child, calc the left subtree size starting from its grandparent node(bc grandparent is smaller than the node, but parent is not)
            p=p->parent;
        while(x->value>p->value && p->parent!=NULL) //calc left subtree size of all of its parent nodes till its greater than its parent
        {
            less_valued_nodes=less_valued_nodes+tree_size(p->left);
            p=p->parent;
            less_valued_nodes++;
        }
    }
    return less_valued_nodes;
}

node* Tree_search_node(node *x,int key)
{
    if(x->value==key || x==NULL)
        return x;
    if(key<x->value)
        return Tree_search_node(x->left,key);
    if(key>x->value)
        return Tree_search_node(x->right,key);
}

int Tree_search_int(node *x,int key)
{
    if( x==NULL)
        return 0;
    else if(x->value==key)
        return x->value;
    else if(key<x->value)
        return Tree_search_int(x->left,key);
    else if(key>x->value)
        return Tree_search_int(x->right,key);
}


node* Tree_minimum(node *x)
{
    while(x->left!=NULL)
        x=x->left;
    return x;
}

node* Tree_maximum(node *x)
{
    while(x->right!=NULL)
        x=x->right;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int v,n,i,r,cnt=0;
    node *root;
    root=NULL;

    while(1)
    {
        cin>>v;
        if(v==-1) break;
        root=recursive_insert(root,v);
    }
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>r;
        node* temp;
        int chk=Tree_search_int(root,r);
        if(chk!=r) cout<<"Reservation not found"<<endl;
        else
        {
            temp=Tree_search_node(root,r);
            cout<<nodes_with_lesser_value(root,temp)<<endl;
        }
    }
}

//50 75 25 29 45 60 10 5 27 15 55 80 -1
