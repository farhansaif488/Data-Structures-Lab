#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int,int> mp;
    int x;
    vector<int> v;
    while(cin>>x)
    {
        if(x==-1)break;
        v.push_back(x);
    }
    mp[v[0]]=1;
    for(int i=1;i<v.size();i++)
    {
        int flag =1;
        int y;
        y=v[i];
        for(auto p:mp)
        {
            pair<int,int> n=p;
            int a = n.first;
            if(y!=a && ((y>0 && y>a+3)||(y>0 && y<a-3)))
            {
                continue;
            }
            flag =0;
            break;
        }
        if(flag)mp[y]=1;
        for(auto p:mp)
        {
            pair<int,int> n=p;
            cout<<n.first<<" ";
        }
        if(flag ==0)
        {
            printf("(Reservation failed)");
        }
        printf("\n");
    }
}