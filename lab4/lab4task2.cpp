#include <bits/stdc++.h>
#define  MAXN 10
using namespace std;
 stack<int>s;
void show_items()
{
    printf("SIZE : %d ",s.size());
    if(s.size()==0)
    {
        cout<<"NULL";
    }
    if(s.size()>0)
    while(s.size())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}

int main()
{
    while(1)
    {

        int m;
        cin>>m;
        if(m==1)
        {
            int b;
            cin>>b;
            if(s.size()>MAXN)
            {
                continue;
            }
            s.push(b);
            show_items();
            cout<<endl;
        }
        else if(m==2)
        {
            int b;
            cin>>b;
            s.pop();
            show_items();
            cout<<endl;
        }
        else{
            break;
        }
    }

    return 0;
}
