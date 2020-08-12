#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n<1)
    {
        cout<<"N must be greater than 0::: input again";
        cin>>n;
    }
    vector<int> v;
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
        mp[x]++;
    }
    int mx =0,mx_i=0;
    int prev_mx=0;
    for(auto x: v)
    {
        prev_mx=mx;
        mx=max(mp[x],mx);
        if(prev_mx != mx)
        {
            mx_i= x;
        }
    }
    printf("Most frequent elemnt : %d\n",mx_i);
    printf("Freq : %d\n",mx);
    
}