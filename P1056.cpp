#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<int,int>p1,pair<int,int>p2)
{
    if(p1.second>p2.second)
    {
        return true;
    }
    return false;
}
int main()
{
    int n,m,line,col;
    cin>>n>>m>>line>>col;
    int count;
    cin>>count;
    vector<pair<int,int>>lines;
    vector<pair<int,int>>cols;
    for(int i=0;i<count;i++)
    {
        int l1,c1,l2,c2;
        cin>>l1>>c1>>l2>>c2;
        if(l1==l2)
        {
            bool find=false;
            int minc=min(c1,c2);
            for(int j=0;j<cols.size();j++)
            {
                if(cols[j].first==minc)
                {
                    find=true;
                    cols[j].second++;
                    break;
                }
            }
            if(find==false)
            {
                cols.emplace_back(make_pair(minc,1));
            }
        }
        else 
        {
            bool find=false;
            int minl=min(l1,l2);
            for(int j=0;j<lines.size();j++)
            {
                if(lines[j].first==minl)
                {
                    find=true;
                    lines[j].second++;
                    break;
                }
            }
            if(find==false)
            {
                lines.emplace_back(make_pair(minl,1));
            }
        }
    }
   // cout<<1;
    sort(lines.begin(),lines.end(),cmp);
    sort(cols.begin(),cols.end(),cmp);
    vector<int>ansl;
    vector<int>ansc;
    for(int i=0;i<lines.size();i++)
    {
        if(line<=0)
        {
            break;
        }
        //cout<<lines[i].first<<" ";
        ansl.emplace_back(lines[i].first);
        line--;
    }

    for(int i=0;i<cols.size();i++)
    {
        if(col<=0)
        {
            break;
        }
        //cout<<cols[i].first<<" ";
        ansc.emplace_back(cols[i].first);
        col--;
    }
    sort(ansl.begin(),ansl.end(),less<int>());
    sort(ansc.begin(),ansc.end(),less<int>());
    for(int i=0;i<ansl.size();i++)
    {
        cout<<ansl[i]<<" ";
    }
    cout<<endl;
    for(int j=0;j<ansc.size();j++)
    {
        cout<<ansc[j]<<" ";
    }
    return 0;
}
/*
/*
10 10 7 8 30
7 2 8 2
1 2 2 2
9 10 10 10
8 9 7 9
9 8 10 8
5 9 6 9
7 1 8 1
3 10 2 10
5 3 5 2
10 9 10 10
8 8 8 9
10 6 10 7
9 2 10 2
4 2 4 1
10 6 10 5
1 2 1 1
9 1 8 1
5 4 5 5
4 10 4 9
9 2 9 1
9 6 9 7
6 6 6 5
5 10 6 10
4 4 5 4
5 8 5 7
8 6 9 6
8 4 9 4
5 3 6 3
10 6 9 6
6 5 6 4

1 2 4 5 7 8 9
1 2 4 5 6 7 8 9

*/
