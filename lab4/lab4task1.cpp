#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Stack {
    int top;

public:
    int a[MAX];
    int cnt;
    Stack() {
        top = -1;
        cnt = 0;
        }
    bool push(int x);
    int pop();
    int tp();
    void show_items();
    bool isEmpty();
};

bool Stack::push(int x)
{
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
            cnt++;
        a[++top] = x;
        return true;
    }
}

int Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        cnt--;
        int x = a[top--];
        return x;
    }
}
int Stack::tp()
{
    if (top < 0) {

        return 0;
    }
    else {
        int x = a[top];
        return x;
    }
}
void Stack::show_items()
{
    if(cnt==0)cout<<"NULL";
    else
    {
        cout<<"Size:";
        cout<<cnt;
        cout<<"Items: ";
        for(int i=top;i<cnt;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}
bool Stack::isEmpty()
{
    return (top < 0);
}


int main()
{
    while(1)
    {
        Stack s;
        int m;
        cin>>m;
        if(m==1)
        {
            int b;
            cin>>b;
            s.push(b);
            s.show_items();
            cout<<endl;
        }
        else if(m==2)
        {
            int b;
            cin>>b;
            s.pop();
            s.show_items();
            cout<<endl;
        }
        else{
            break;
        }
    }

    return 0;
}
