

#include <bits/stdc++.h>
using namespace std;
/*

Heap_Min()
- Heap_extract_min()
- Min_heap_insert()
- Heap_decrease_key()

*/
void heapify(int arr[], int n, int i)
{
    int minest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;


    if (l < n && arr[l] < arr[minest])
        minest = l;


    if (r < n && arr[r] < arr[minest])
        minest = r;


    if (minest != i) {
        swap(arr[i], arr[minest]);


        heapify(arr, n, minest);
    }
}


void build_min_heap(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

}

void Heap_Min(int arr[],int n)
{
    cout<<arr[0];
}
void Heap_Extract_Min(int arr[],int *n)
{
        swap(arr[0],arr[*n-1]);
        *n=*n-1;
        build_min_heap(arr,*n);
}
void Min_Heap_Insert(int arr[],int x,int *n)
{
    *n=*n+1;
    arr[*n-1]=x;
    build_min_heap(arr,*n);
}





void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    build_min_heap(arr, n);
    printArray(arr, n);
    cout<<endl;
    Heap_Min(arr,n);
    cout<<endl;
    Heap_Extract_Min(arr,&n);//called only one time
    Heap_Min(arr,n);
    Min_Heap_Insert(arr,1,&n);
    Heap_Min(arr,n);
    cout<<endl;
    printArray(arr, n);
}
