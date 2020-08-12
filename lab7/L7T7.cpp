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

node* Tree_search(node *x,int key)
{
    if(x->value==key || x==NULL)
        return x;
    if(key<x->value)
        return Tree_search(x->left,key);
    if(key>x->value)
        return Tree_search(x->right,key);
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

node* Successor(node *x)
{
    if(x->right!=NULL)
        return Tree_minimum(x->right);
    else
    {
        node *p=new node();
        p=x->parent;
        while(x->value > p->value && p!=NULL)
            p=p->parent;
        return p;
    }
}

node* Predessor(node *x)
{
    if(x->left!=NULL)
        return Tree_maximum(x->left);
    else
    {
        node *p=new node();
        p=x->parent;
        while(x->value < p->value && p!=NULL)
            p=p->parent;
        return p;
    }
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

void inorder(node *x)
{
    if(x != NULL)
    {
        inorder(x->left);
        cout<<x->value<<" ";
        inorder(x->right);
    }
}

void preorder(node *x)
{
    if(x != NULL)
    {
        cout<<x->value<<" ";
        preorder(x->left);
        preorder(x->right);
    }
}

void postorder(node *x)
{
    if(x != NULL)
    {
        postorder(x->left);
        postorder(x->right);
        cout<<x->value<<" ";
    }
}

void nthPreordernode(node* x, int n)
{
    static int count = 0;
    if (x == NULL)
        return;
    if (count <= n)
    {
        count++;
        if (count == n)
            cout <<"preorder "<<x->value<<endl;
        nthPreordernode(x->left, n);
        nthPreordernode(x->right, n);
    }
}

void nthInordernode(node* x, int n)
{
    static int count = 0;
    if (x == NULL)
        return;
    if (count <= n)
    {
        nthInordernode(x->left, n);
        count++;
        if (count == n)
            cout <<"inorder "<<x->value<<endl;
        nthInordernode(x->right, n);
    }
}

void nthPostordernode(node* x, int n)
{
    static int count = 0;
    if (x == NULL)
        return;
    if (count <= n)
    {
        nthPostordernode(x->left, n);
        nthPostordernode(x->right, n);
        count++;
        if (count == n)
            cout <<"postorder "<<x->value<<endl;
    }
}

node* Delete_node(node* x,int key)
{
    if(x==NULL) return x;//if tree has nothing
    if(key<x->value)//key is in left subtree
        x->left=Delete_node(x->left,key);
    else if(key>x->value)//key is in right subtree
        x->right=Delete_node(x->right,key);
    else
    {
        if(x->left==NULL)
        {
            node* temp=new node();
            temp=x->right;
            return temp;
        }
        else if(x->right==NULL)
        {
            node* temp=new node();
            temp=x->left;
            return temp;
        }
        else
        {
            node* temp=new node();
            temp=Tree_minimum(x->right);
            x->value=temp->value;
            x->right=Delete_node(x->right,temp->value);
            return x;
        }

    }
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

/*int Tree_height(node* x) //height if u want to use the other levelorder
{
    int lh=0;
    int rh=0;
    if (x == NULL)
        return 0;
    else
    {
        lh = Tree_height(x->left);
        rh = Tree_height(x->right);

        return 1+max(lh,rh);
    }
}*/

void leftView(node* x)
{
    if (x==NULL)
        return;
    leftView(x->left);
    cout << x->value << " ";
}

void rightView(node* x)
{
    if (x==NULL)
        return;
    cout << x->value << " ";
    rightView(x->right);
}

void TopView(node * x)
{
    leftView(x);
    rightView(x->right);
}

void printLevelOrder(node *root)
{
    // Base Case
    if (root == NULL)  return;

    // Create an empty queue for level order tarversal
    queue<node *> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false)
    {
        // Print front of queue and remove it from queue
        node *node = q.front();
        cout << node->value << " ";
        q.pop();


        if (node->left != NULL)
            q.push(node->left);


        if (node->right != NULL)
            q.push(node->right);
    }
}

/*void printLevel(node* x,int level)
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
}

void printLevelOrder(node* x)
{
    int h=Tree_height(x);
    for(int i=1; i<=h; i++)
        printLevel(x,i);
}*/

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
            Delete_node(root,r);
            printLevelOrder(root);
            cout<<endl;
        }
    }
}

