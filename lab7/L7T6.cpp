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

int max_with_ancestor(node* a, int n)
{
    int max_n=INT_MIN;
    while(n!=a->value)
    {
        if(n<a->value)
        {
            max_n=max(max_n,a->value);
            a=a->left;
        }
        else
        {
            max_n=max(max_n,a->value);
            a=a->right;
        }
    }
    return max(max_n,n);
}

int max_with_node(node* a,int x,int y)
{
    while((x<a->value && y<a->value)||(x>a->value && y>a->value))
    {
        if(x<a->value && y<a->value)
            a=a->left;
        else if(x>a->value && y>a->value)
            a=a->right;
    }
    return max(max_with_ancestor(a,x),max_with_ancestor(a,y));
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int v,n,i,r1,r2,cnt=0;
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
        cin>>r1>>r2;
        cout<<max_with_node(root,r1,r2)<<endl;
    }
}

//50 75 25 29 45 60 10 5 27 15 55 80 -1
