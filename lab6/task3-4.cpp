
#include <bits/stdc++.h>
using namespace std;
#define Node struct node

struct node{
    int data;
    Node *next;
    Node *prev;
};

Node* create_node(int d)
{

    Node *new_node = new Node;
    new_node->data=d;
    new_node->next=NULL;
    new_node->prev=NULL;
    return new_node;
}

Node* create_dll(int x)
{
    Node *b=create_node(x);
    return b;

}

Node* prepend(Node *head,int x)
{

    Node *new_node=create_node(x);

    new_node->next = head;
    new_node->prev = NULL;

    return new_node;
}
void insert_node(Node *head,int data_pre,int data)
{
    Node *p = head;

    while(p->data != data_pre && p->next!=NULL)
    {
        p=p->next;

    }
    if(p->data == data_pre && p->next !=NULL)
    {
    Node *x = create_node(data);
    ////////x related
    x->next = p->next;
    p->next->prev = x;
    ////////////
    p->next = x;
    x->prev = p;
    }else{
        cout<<"Val not found"<<endl;
    }
}

void append(Node *head,int d)
{
    Node *p=head;

    while(p->next!=NULL)
    {
        p=p->next;
    }
    Node *x = create_node(d);
    p->next = x;
    x->prev = p;
}

void display(Node *head)
{
    Node *p=head;


    while(p->next!=NULL){
        cout<<p->data<<endl;
        p=p->next;
    }
    cout<<p->data<<endl;

}
void revdisplay(Node *head)
{
    Node *p=head;


    while(p->next!=NULL){
       p=p->next;
    }
    while(p->prev != NULL)
    {
        cout<<p->data<<endl;
        p=p->prev;
    }
    cout<<p->data<<endl;
}

Node* del_n(Node *head,int x)
{
    Node *p = head;
    Node *pre;
    while(p->data != x )
    {
        pre=p;
        p=p->next;
    }
    if(head == p)
    {
        Node *q;
        q=head;
        head = head->next;
        delete q;
        return head;
    }
    pre->next = p->next;
    p->next->prev = pre;
    delete p;
    return head;
}
int main()
{
    Node *head = create_dll(10);
     cout<<"<<<<<<<<"<<endl;
    display(head);
   head = prepend(head,20);
    cout<<"<<<<<<<<"<<endl;
   display(head);
   insert_node(head,20,30);
    cout<<"<<<<<<<<"<<endl;
   display(head);
   head = del_n(head,30);
    cout<<"<<<<<<<<"<<endl;
   display(head);
   append(head,5);
   cout<<"<<<<<<<<"<<endl;
    display(head);
}
