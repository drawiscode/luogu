#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int x,y,horse_x,horse_y;
    cin >> x >> y >> horse_x >> horse_y;
    vector<vector<long long int>>a(23,vector<long long int>(23,0));
    vector<vector<bool>>reached(23,vector<bool>(23,true));    
    //初始化不能到达的点
    reached[horse_x][horse_y]=false;
    reached[horse_x+2][horse_y+1]=false;
    reached[horse_x+1][horse_y+2]=false;
    if(horse_x-1>=0)
    {
        reached[horse_x-1][horse_y+2]=false;
        if(horse_y-2>=0)
        {
            reached[horse_x-1][horse_y-2]=false;
        }
    }
    if(horse_x-2>=0)
    {
        reached[horse_x-2][horse_y+1]=false;
        if(horse_y-1>=0)
        {
            reached[horse_x-2][horse_y-1]=false;
        }
    }
    if(horse_y-1>=0)
    {
        reached[horse_x+2][horse_y-1]=false;
    }
    if(horse_y-2>=0)
    {
        reached[horse_x+1][horse_y-2]=false;
    }
    //
    bool zoomed=false;
    a[0][0]=1;
    for(int i=1;i<=x;i++)
    {
        if(reached[i][0]==true&&zoomed==false)
        {
            a[i][0]=1;
        }   
        else
        {
            zoomed=true;
        }    
    }
    zoomed=false;
    for(int j=1;j<=y;j++)
    {
        if(reached[0][j]==true&&zoomed==false)
        {
            a[0][j]=1;
        }
        else
        {
            zoomed=true;
        }
    }
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=y;j++)
        {
            if(reached[i][j]==true)
            {
                a[i][j]=a[i-1][j]+a[i][j-1];
            }
        }
    }
    cout<<a[x][y]<<endl;
    return 0;
}