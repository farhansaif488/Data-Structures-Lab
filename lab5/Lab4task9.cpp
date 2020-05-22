#include<bits/stdc++.h>
using namespace std;
int main()
{
    int cnt=0,result;
    char ch;
    string str;
    cin>>str;
    stack<char>s;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='(')
            s.push(str[i]);
        else
        {
            if(s.size()==0)
                cnt++;
            else if(s.top()=='(')
                s.pop();
            else
                cnt++;
        }
    }
    result=s.size()+cnt;
    cout<<result;
    return 0;
}
