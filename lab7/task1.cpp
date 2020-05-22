
#include <bits/stdc++.h> 
using namespace std; 
  
int count1= 0;

struct Node { 
    int key; 
    struct Node *left, *right; 
}; 

Node* newNode(int data) 
{ 
    Node* temp = new Node; 
  
    temp->key = data; 
  
    temp->left = NULL; 
    temp->right = NULL; 
  
    return temp; 
} 
  

Node* insert(Node* root, int key) 
{ 
   
    Node* newnode = newNode(key); 
  
  
    Node* x = root; 
  
   
    Node* y = NULL; 
    Node* p = NULL;
    Node* q = NULL;
  
    while (x != NULL) { 
        y = x; 
        if (key < x->key) 
            x = x->left; 
        else
            x = x->right; 
    } 
    
    p = y->left;
    q = y->right;
 
    if (y == NULL) 
        y = newnode; 

    else if (key < y->key && (abs(key-(y->key)>=3) && (abs(key-(p->key)>=3) && (abs(key-(q->key)>=3)) 
        y->left = newnode; 
  
   
    else if((key > y->key && (abs(key-(y->key)>=3)))
        y->right = newnode; 
  

    return y; 
} 
  

int Inorder(Node* root) 
{ 
    if (root == NULL) 
        return; 
    else { 
        Inorder(root->left); 
        
        Inorder(root->right); 
    }
    return;  
} 
void inorderx(Node* root) 
{ 
    if (root == NULL) 
        return; 
    else { 
        Inorder(root->left); 
        cout<<root->key<<endl; 
        Inorder(root->right); 
    }
    return;  
} 


int main() 
{ 
 
    ll tc;
    Node *root = NULL;
    prev = 0;

    while(1)
    {
        cin>>tc;
       
        if(tc!=-1)
        {
            if(root == NULL)
                root=insert(root,tc);
            else
            {
                insert(root,tc);
                if(Inorder(root)==prev)
                {
                    inorderx(root);
                    
                }else{
                    inorderx(root);
                    cout<<"(reservation error)"<<endl;
                    prev = Inorder(root);
                }
            }
            continue;
        }
        break;
    }



}