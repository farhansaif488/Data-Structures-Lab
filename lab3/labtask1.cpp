#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<double> v,q;
        q.push_back(0);
        while(1)
        {
            double x;
            cin>>x;
            if(x==-1)
            {
                break;
            }
            v.push_back(x);
            q.push_back(0);
        }
        for(int j=0;j<v.size();j++)
        {
            double p;
            cin>>p;
            q[v[j]]=p;
        }
        for(int i=1;i<q.size();i++)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
