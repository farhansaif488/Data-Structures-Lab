#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int,int>mp1,mp2;

    int n,n2;
    cin>>n>>n2;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        v.push_back(x);
        mp1.insert({x,0});
    }

    for(int i=0;i<n2;i++)
    {
        int x;
        cin>>x;
        mp1[x]++;
    }
    int cnt=0;
    for(auto k: v)
    {
        if(mp1[k]>0)
        {
            cnt++;
        }
    }
    if(cnt==n2)
    {
        cout<<"yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    
}