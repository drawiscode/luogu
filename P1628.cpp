#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<string>datas;
vector<string>sort_datas;
bool cmp(string s1,string s2)
{
    return s1<s2;
}
int main()
{
    int n;
    cin>>n;
    string t;
    datas.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>datas[i];
    }
    cin>>t;
    for(int i=0;i<n;i++)
    {
        bool add=true;
        for(int j=0;j<t.size();j++)
        {
            if(t[j]!=datas[i][j])
            {
                add=false;
                break;
            }
        }
        if(add)
        {
            sort_datas.emplace_back(datas[i]);
        }
    }
    sort(sort_datas.begin(),sort_datas.end(),cmp);
    for(int i=0;i<sort_datas.size();i++)
    {
        cout<<sort_datas[i]<<endl;
    }
    return 0;
}