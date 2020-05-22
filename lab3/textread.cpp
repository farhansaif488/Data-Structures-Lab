#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {
    int sum = 0;
   /* string x;
    string y;
    int M,siz,n;
    ifstream fileread;

    fileread.open("test.txt");
    if (!fileread) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    fileread>>M;
*/
    while(M--)
    {
        fileread>>siz;
        fileread>>n;
        for(int i=0;i<n;i++)
        {
            fileread>>x;
            cout<<x<<endl;
        }
    }
}

