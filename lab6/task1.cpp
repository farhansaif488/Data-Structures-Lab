#include <bits/stdc++.h>
using namespace std;
#define Node struct node

struct node{
    int data;
    Node *next;
};

Node* create_node(int d)
{

    Node *new_node = new Node;
    new_node->data=d;
    new_node->next=NULL;
    return new_node;
}

Node* create_sll(int x)
{
    Node *b=create_node(x);
    return b;

}

Node* prepend(Node *head,int x)
{

    Node *new_node=create_node(x);

    new_node->next = head;
    head = new_node;
    return head;
}
void insert_node(Node *head,int data_pre,int data)
{
    Node *p = head;
    int f  = 1;
    while(p->data != data_pre && p->next!=NULL)
    {
        p=p->next;

    }
    if(p->data == data_pre && p->next !=NULL)
    {
    Node *x = create_node(data);

    x->next = p->next;
    p->next = x;
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
}

void display(Node *head)
{
    Node *p=head;

    while(p->next!=NULL)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
    cout<<p->data<<endl;

}

Node* del_n(Node *head,int x)
{
    Node *p = head;
    Node *prev;
    while(p->data != x )
    {
        prev=p;
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
    prev->next = p->next;
    delete p;
    return head;
}

int main()
{
    Node *head = create_sll(10);
    head = prepend(head,20);
    cout<<"<<<<DISPLAY<<<"<<endl;
    display(head);
    //cout<<"<<<<DISPLAY<<<"<<endl;
    insert_node(head,20,30);
    cout<<"<<<<DISPLAY<<<"<<endl;
    display(head);

    append(head,5);
     cout<<"<<<<DISPLAY<<<"<<endl;
     display(head);
    insert_node(head,15,17);
    cout<<"<<<<DISPLAY<<<"<<endl;
    display(head);
    append(head,22);
    del_n(head,22);
    cout<<"<<<<DISPLAY<<<"<<endl;
    display(head);
}
