#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        long double x;
        long double d;
        cin>>d;



        long double expression;
        long double expression2;
        expression = d/(x+1);
        expression = ceil(expression);
        expression2 = x+expression;
        if(expression2<n)
        {
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
    }
}
