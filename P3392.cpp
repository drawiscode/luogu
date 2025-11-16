#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string>strs;
vector<vector<int>>counts;
vector<vector<int>>ans;
int n;
int m;
void TraceBack(int k,vector<int>&temp)
{
    int sum=0;
    for(int i=0;i<temp.size();i++)
    {
        sum+=temp[i];
    }
    if(temp.size()==3&&sum==n)
    {
        ans.emplace_back(temp);
        return;
    }
    else if(temp.size()==3)
    {
        return;
    }
    for(int i=1;i<n;i++)
    {
        temp.emplace_back(i);
        TraceBack(k+1,temp);
        temp.pop_back();
    }
}
int main()
{
    //int n,m;
    cin>>n>>m;
    strs.resize(n);
    counts.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>strs[i];
        int W=0;
        int B=0;
        int R=0;
        for(int j=0;j<strs[i].size();j++)
        {
            if(strs[i][j]=='W')
            {
                W++;
            }
            else if(strs[i][j]=='B')
            {
                B++;
            }
            else
            {
                R++;
            }
        }
        counts[i].emplace_back(W);
        counts[i].emplace_back(B);
        counts[i].emplace_back(R);
    }
    vector<int>temp;
    TraceBack(1,temp);
    int result=m*n;
    for(int i=0;i<ans.size();i++)
    {
        int W=ans[i][0];
        int B=ans[i][1];
        int R=ans[i][2];
        int node=0;
        for(int j=0;j<W;j++)
        {
            int countW=counts[j][0];
            node+=(m-countW);
        }
        for(int j=W;j<W+B;j++)
        {
            int countB=counts[j][1];
            node+=(m-countB);
        }
        for(int j=W+B;j<W+B+R;j++)
        {
            int countR=counts[j][2];
            node+=(m-countR);
        }
        if(node<result)
        {
            result=node;
        }
    }
    cout<<result;
    return 0;
}
/*
4 5
WRWRW
BWRWB
WRWRW
RWBWR
*/