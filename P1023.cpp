#include <iostream>
#include <vector>
using namespace std;
int should_be_price;
int chengben;
int chengben_xiaoliang;
vector<pair<int,int>>datas;
int per_inc_dec;

bool Oper(int price)
{
    int addx=price-should_be_price;
    int maxW=0;
    int maxW_price=0;
    for(int i=0;i<=datas.size();i++)
    {
        int nodeprice=datas[i].first;
        int nodexiaoliang=datas[i].second;
        int W=(addx+nodeprice-chengben)*nodexiaoliang;
        if(W>maxW)
        {
            W=maxW;
            maxW_price=nodeprice;
        }
    }
    if(price==maxW_price+addx)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    cin>>should_be_price>>chengben>>chengben_xiaoliang;
    while(1)
    {
        int x,y;
        cin>>x>>y;
        if(x==-1&&y==-1)
        {
            break;
        }
        else
        {
            datas.emplace_back(make_pair(x,y));
        }
    }
    cin>>per_inc_dec;

    int left=chengben;
    int maxprice=datas[datas.size()-1].first;
    int maxprice_xiaoliang=datas[datas.size()-1].second;
    int right=maxprice+(maxprice_xiaoliang/per_inc_dec);

    int count=maxprice_xiaoliang/per_inc_dec;
    for(int i=1;i<=count;i++)
    {
        datas.emplace_back(make_pair(maxprice+i,maxprice_xiaoliang-i*per_inc_dec));
    }

    int ans=-100001;
    for(int i=left;i<=right;i++)
    {
        if(Oper(i))
        {
            ans=i-should_be_price;
        }
    }
    if(ans==-100001)
    {
        cout<<"NO SOLUTION";
    }
    else
    {
        cout<<ans;
    }
    return 0;
}