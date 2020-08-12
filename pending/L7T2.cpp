#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int,int> mp;
    while(1)
    {
        int x;cin>>x;
        if(x==-1)break;
        mp[x]=1;
    }
    for(auto p:mp)
    {
        cout<<p.first<<" ";
    }
}