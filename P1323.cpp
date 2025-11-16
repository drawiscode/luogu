#include<iostream>
#include <vector>
#include <set>
#include <queue>
#include <string>
using namespace std;
set<int>uses;
priority_queue<int,vector<int>,greater<int>>p_q;
queue<int>results;
string ans;
void delete_string(int m)
{
    int count=0;
    while(count<m)
    {
        count++;
        int len=ans.size();
        bool delete_char=false;
        for(int i=0;i<len-1;i++)
        {
            if(ans[i]<ans[i+1])
            {
                ans.erase(i,1);
                delete_char=true;
                break;
            }
        }

        if(!delete_char)
        {
            //删除最后一个元素
            ans.erase(len-1);
        }
    }
}

int main()
{
    int k,m;
    cin>>k>>m;
    
    //初始化
    results.push(1);
    p_q.push(3);
    p_q.push(9);
    int count=1;
    uses.insert(1);

    //找到最小的K个数
    while(count<k)
    {
        count++;

        //判断是否用过这个元素
        bool have_use=true;
        while(have_use)
        {
            int node=p_q.top();
            p_q.pop();

            if(uses.find(node)==uses.end())//没有这个元素
            {
                have_use=false;

                p_q.push(2*node+1);
                p_q.push(4*node+5);
                
                results.push(node);
                uses.insert(node);
            }
            else//有过这个元素
            {
                ;
            }
        }
    }
    //获得字符串string ans
    ans="";
    for(int i=0;i<k;i++)
    {
        ans+=to_string(results.front());
        results.pop();
    }
    cout<<ans<<endl;
    delete_string(m);
    cout<<ans;
    return 0;
}