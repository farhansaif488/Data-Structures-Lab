#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    vector<long long int> p,v;
    ifstream fileread;
    fileread.open("test3.txt");

    fileread>>n;
    for(long long i =0;i<2*n;i++)
    {
        long long int x;
        fileread>>x;
        p.push_back(x);
    }
    fileread.close();
    sort(p.rbegin(),p.rend());
    long long int sum =0;
    for(long long int i = 0;i<p.size();i+=2)
    {
        sum+=min(p[i],p[i+1]);
    }

    cout<<sum<<endl;

}
