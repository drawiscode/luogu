#include <iostream>
#include <vector>
using namespace std;
int n;
int m;
int counts=-1;
vector<int>datas;
vector<int>temp;
vector<int>ans;
/*
3 1
1 2 3
*/
void TraceBack(int index,vector<bool>visit)
{
    if(counts==m)
    {
        return;
    }
    if(index==n)
    {
        counts++;
        if(counts==0)
        {
            visit[datas[index]]=false;
            temp.pop_back();
        }
        if(counts==m)
        {
            for(int i=1;i<=n;i++)
            {
                if(visit[i]==false)
                {
                    temp.emplace_back(i);
                    ans=temp;
                    break;
                }
            }
        }
        return;
    }
    for(int i=datas[index];i<=n;i++)
    {
        if(visit[i])
        {
            TraceBack(index+1,visit);
            visit[i]=false;
            temp.pop_back();
        }
        else
        {
            visit[i]=true;
            temp.emplace_back(i);
            TraceBack(index+1,visit);
            visit[i]=false;
            temp.pop_back();
        }
    }
}
int main()
{
    cin>>n>>m;  
    //count=0;
    datas.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>datas[i];
    }
    temp=datas;
    vector<bool>visit(n+1,true);
    TraceBack(1,visit);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}