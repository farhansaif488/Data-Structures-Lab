#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,zero,cnt=0,cnt2=0,cnt3=0;
    cin>>n;
    int arr[n];
    int duplicate[n]={0};
    stack<int>s;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>zero;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
            s.push(arr[i]);
        else
            duplicate[cnt++]=arr[i];
    }
    duplicate[cnt++]=arr[n-1];
    for(int i=0;i<n;i++)
    {
        if(s.top()<duplicate[cnt2])
        {
            arr[i]=s.top();
            s.pop();
            cnt3++;
        }
        else if(duplicate[cnt2]>0)
            arr[i]=duplicate[cnt2++];
    }
    cnt2+=cnt3;
    for(int i=cnt2;i<n;i++)
    {
        arr[i]=s.top();
        s.pop();
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}
