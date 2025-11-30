#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;
struct Node
{
    int left;
    int right;
    int n_left;
    int n_right;
    int count;
    Node(int u):left(u),right(u),n_left(u-1),n_right(u+1),count(1){}
};
vector<Node>datas;
void Insert(int u,int index)
{
    if(datas[index].n_left==u)
    {
        datas[index].n_left=u-1;
        datas[index].left=u;
        datas[index].count=datas[index].count+1;
        
        int insert_datas_count=INT32_MAX;
        int insert_index=-1;
        for(int i=0;i<datas.size();i++)
        {
            if(datas[i].n_right==u&&datas[i].count<insert_datas_count)
            {
                insert_index=i;
                insert_datas_count=datas[i].count;
            }
        }
        if(insert_index!=-1)
        {
            datas[index].n_left=datas[insert_index].n_left;
            datas[index].left=datas[insert_index].left;
            datas[index].count+=datas[insert_index].count;
            datas.erase(datas.begin()+insert_index);
            return;
        }
        return;
    }
    else
    {
        datas[index].n_right=u+1;
        datas[index].right=u;
        datas[index].count=datas[index].count+1;

          
        int insert_datas_count=INT32_MAX;
        int insert_index=-1;
        for(int i=0;i<datas.size();i++)
        {
            if(datas[i].n_left==u&&datas[i].count<insert_datas_count)
            {
                insert_index=i;
                insert_datas_count=datas[i].count;
            }
        }
        if(insert_index!=-1)
        {
            datas[index].n_right=datas[insert_index].n_right;
            datas[index].right=datas[insert_index].right;
            datas[index].count+=datas[insert_index].count;
            datas.erase(datas.begin()+insert_index);
            return;
        }
        return;
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int u;
        cin>>u;
        bool insert=false;
        int insert_datas_count=INT32_MAX;
        int insert_index=-1;
        bool have_this_num=false;
        for(int j=0;j<datas.size();j++)
        {
            if(datas[j].left<=u&&datas[j].right>=u)
            {
                have_this_num=true;
                break;
            }
            if(datas[j].n_left==u&&datas[j].count<insert_datas_count)
            {
                insert_datas_count=datas[j].count;
                insert_index=j;
            }
            else if(datas[j].n_right==u&&datas[j].count<insert_datas_count)
            {
                insert_datas_count=datas[j].count;
                insert_index=j;
            }
        }
        if(have_this_num==true)
        {
            continue;
        }
        if(insert_index!=-1)
        {
            Insert(u,insert_index);
        }
        else
        {
            Node node(u);
            datas.emplace_back(node);
        }
    }
    int mincount=INT32_MAX;
    for(int i=0;i<datas.size();i++)
    {
        if(mincount>datas[i].count)
        {
            mincount=datas[i].count;
        }
    }
    cout<<mincount;
    return 0;
}