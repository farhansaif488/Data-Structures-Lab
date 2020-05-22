
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll arr[10000000];

void insertion_sort(ll arr[], ll n)
{
    ll i, key, j,cnt=0;
    clock_t total_clock_ticks;
    cout<<endl;
    cout<<"Applying Insertion sort . . ."<<endl;
    total_clock_ticks  = clock();
    for (j =2 ; j <= n; j++)
    {
        key = arr[j];
        i = j - 1;
        while (i > 0 && arr[i] > key)
        {
            arr[i + 1] = arr[i];
            i = i - 1;
            cnt++;
        }
        arr[i + 1] = key;
    }
    cout<<"Total comparisons: "<<cnt<<endl;
    total_clock_ticks = clock()- total_clock_ticks;
    cout<<"Total clock ticks: "<<total_clock_ticks<<setprecision(12)<<"("<<(float)total_clock_ticks/CLOCKS_PER_SEC<<" seconds)"<<endl;
    cout<<endl;
}

void bubble_sort(ll arr[], ll n)
{
    ll i, j,cnt=0;
    clock_t total_clock_ticks;
    cout<<endl;
    cout<<"Applying Bubble sort . . ."<<endl;
    total_clock_ticks = clock();
    for (i = 1; i <= n-1; i++)
    {
        for (j = n; j>=i+1; j--)
        {
            cnt++;
            if (arr[j] < arr[j-1])
            {
                ll temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
    cout<<"Total comparisons: "<<cnt<<endl;
    total_clock_ticks= clock()-total_clock_ticks;
    cout<<"Total clock ticks: "<<total_clock_ticks<<setprecision(12)<<"("<<(float)total_clock_ticks/CLOCKS_PER_SEC<<" seconds)"<<endl;
    cout<<endl;
}


int main()
{
    ll n,i,flag=0;
    cout<<"Give size of Input: ";
    cin>>n;
    srand(time(0));
    cout<<endl;
    cout<<"Generating random input set . . .";
    for(i=0; i<n; i++)
    {
        arr[i]=rand();
        flag=1;
    }
    if(flag==1) cout<<" Done."<<endl;
    else cout<<" Failed."<<endl;
    cout<<endl;

    insertion_sort(arr,n);
    bubble_sort(arr,n);

    return 0;
}
