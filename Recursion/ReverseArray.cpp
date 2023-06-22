#include<bits/stdc++.h>
using namespace std;


void fun(vector<int> &vec)
{
    if(vec.size()==1)
        return;
    int ele=vec[vec.size()-1];
    vec.pop_back();
    fun(vec);
    vec.insert(vec.begin(),ele);
}
int main()
{
    vector<int> vec={1,2,3,4,5,6};
    fun(vec);
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
}