#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin>>n;
    int a[10000];
    map<int,int>ase;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        ase[a[i]]++;
    }

    map<pair<int,int>,int>mp;

    int sum;
    cin>>sum;


    for(int i=0;i<n;i++)
    {
        int temp=sum-a[i];
        if(ase[temp])
        {
            int c=a[i];
            int b=temp;
            if(c<b)
            {
                mp[make_pair(c,b)]++;
            }
            else
            {
                mp[make_pair(b,c)]++;

            }
        }
    }

 
    for(auto x: mp)
    {
        cout<<x.first.first<<" "<<x.first.second<<endl;

     
    }



}