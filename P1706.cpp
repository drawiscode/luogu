#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
vector<int>datas;
vector<vector<int>>ans;
void A(vector<int>temp,vector<bool>visit)
{
    int n=datas.size()-1;
    if(temp.size()==n)
    {
        ans.emplace_back(temp);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==false)
        {
            temp.emplace_back(i);
            visit[i]=true;
            A(temp,visit);
            temp.pop_back();
            visit[i]=false;
        }
    }
}
void Print()
{
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<setw(5)<<ans[i][j];
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    datas.resize(n+1);
    for(int i=0;i<=n;i++)
    {
        datas[i]=i;
    }
    vector<int>temp;
    vector<bool>visit(n+1,false);
    A(temp,visit);
    Print();
    return 0;
}