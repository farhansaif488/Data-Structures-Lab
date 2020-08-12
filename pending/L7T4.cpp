#include<bits/stdc++.h>
#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};


struct Node* Find_min( Node* root)
{
    if(root == NULL)
    {
        return NULL;
    }
    while(root->left != NULL)
        root = root->left;
    return root;
}


void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if (root == NULL)  return ;

    if (root->data == key)
    {
        if (root->left != NULL)
        {
            Node* tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp ;
        }
        if (root->right != NULL)
        {
            Node* tmp = root->right ;
            while (tmp->left)
                tmp = tmp->left ;
            suc = tmp ;
        }
        return ;
    }
    if (root->data > key)
    {
        suc = root ;
        findPreSuc(root->left, pre, suc, key) ;
    }
    else
    {
        pre = root ;
        findPreSuc(root->right, pre, suc, key) ;
    }
}

void display(Node *root)
{
    if(root == NULL)
        return;

    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}
Node *create_node(int item)
{
    Node *new_node=new Node();
    new_node->data=item;
    new_node->right=NULL;
    new_node->left=NULL;

    return new_node;
}

Node *Insert(int item, Node *root)
{
    if(root==NULL)
    {
        root=create_node(item);
    }

    else if(item<=root->data)
    {
        if(item !=(root->data-3))
            root->left=Insert(item,root->left);
        else
        {
            cout<<"Reservation Failed"<<endl;
        }
    }

    else if(item> root->data)
    {
        if(item!=(root->data +3))
            root->right=Insert(item,root->right);

        else
        {
            cout<<"Reservation Failed"<<endl;
        }
    }

    return root;
}

int main()
{

    Node* root = NULL;
    cout<<"Inserted elements:   ";
    root=Insert(10,root);
    root=Insert(25,root);
    root=Insert(29,root);
    root=Insert(45,root);
    root=Insert(50,root);
    root=Insert(60,root);
    root=Insert(75,root);
    display(root);
    cout<<"\n";

    int value,test,key;
    cin>>test;
    while(test--)
    {
        cin>>key;
        Node* pre = NULL, *suc = NULL;

    findPreSuc(root, pre, suc, key);
    if (pre != NULL)
      cout << "Predecessor is " << pre->data << endl;
    else
      cout << "NULL"<<endl;

    if (suc != NULL)
      cout << "Successor is " << suc->data<<endl;
    else
      cout << "NULL"<<endl;

    }
}

