#include <bits/stdc++.h>
using namespace std;
#define p pair<string,int>
bool cmp(p a,p b)
{
    return a.second<b.second;
}
int main()
{

    ifstream fileread;
    int M;
    fileread.open("test.txt");
    if (!fileread) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    fileread>>M;



    while(M--){
    string s;
    int siz;
    int n;
    int c;
    fileread>>siz;
    fileread>>n;
    vector<p> vec;

    for(int l=0;l<n;l++)
    {
        fileread>>s;

        c = 0;
        for(int i=0;i<s.size()-1;i++)
        {

            for(int j=i+1;j<s.size();j++)
            {
                if(s[i]>s[j])
                {
                    c++;

                }
            }


        }
        vec.push_back({s,c});
    }
    fileread.close();
    sort(vec.begin(),vec.end(),cmp);
    for(auto x:vec)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }

    }

}
