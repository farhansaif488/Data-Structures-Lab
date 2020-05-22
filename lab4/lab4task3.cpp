
#include <bits/stdc++.h>
using namespace std;



int main()
{
    vector<stack<char>> x;
    int n;
    cin>>n;
    while(n--){
    stack<char> s;
    string c;
    cin>>c;
    for(int i=0;i<c.size();i++)
    {
        s.push(char(c[i]));
    }
    x.push_back(s);
    }
    for(auto p : x)
    {
        while(p.size())
        {
            cout<<p.top();
            p.pop();
        }
        cout<<endl;
    }
}
