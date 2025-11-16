#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>datas;
vector<vector<int>>ans;
int r;
void TraceBack(int k,vector<int>temp)
{
    int n=datas.size()-1;
    if(temp.size()==r)
    {
        ans.emplace_back(temp);
        return;
    }
    if(k>n)
    {
        return;
    }
    temp.emplace_back(datas[k]);
    TraceBack(k+1,temp);
    temp.pop_back();
    TraceBack(k+1,temp);
}
int main()
{
    int n;
    cin>>n>>r;
    datas.resize(n+1);
    for(int i=0;i<=n;i++)
    {
        datas[i]=i;
    }
    vector<int>temp;
    TraceBack(1,temp);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<setw(3)<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}