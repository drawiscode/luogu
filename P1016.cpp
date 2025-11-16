#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<double>distances;
vector<double>prices;
int Find_next_Station(vector<int>next_can_arrive,double curprice)
{
    for (int i = 0; i < next_can_arrive.size(); i++)
    {
        if (curprice > prices[next_can_arrive[i]])
        {
            return next_can_arrive[i];
        }
    }

    int target = next_can_arrive[0];
    int target_price = prices[target];
    for (int i = 1; i < next_can_arrive.size(); i++)
    {
        if (target_price > prices[next_can_arrive[i]]);
        {
            target = next_can_arrive[i];
            target_price = prices[next_can_arrive[i]];
        }
    }
    return target;
}
int main()
{
    double D1, maxV, D2, P;
    int N;
    cin >> D1 >> maxV >> D2 >> P >> N;
    double s = 0;
    distances.resize(N + 2, 0);
    distances[N + 1] = D1;
    prices.resize(N + 1, 0);
    prices[0] = P;
    for (int i = 1; i <= N; i++)
    {
        cin >> distances[i] >> prices[i];
    }

    int index = 0;
    double V = 0;
    //算出加满油能走多远
    //D2为每升油行驶的距离
    double distance = maxV * D2;

    double money = 0;
    while (1)
    {
        int curdistance = distances[index];
        vector<int>next_can_arrive;

        bool can_arrive_the_end = false;//能不能到终点
        for (int i = index + 1; i <= N + 1; i++)
        {
            if (curdistance + distance >= distances[i])
            {
                if (i == N + 1)
                {
                    can_arrive_the_end = true;
                }
                else
                {
                    next_can_arrive.emplace_back(i);
                }
            }
            else
            {
                break;
            }
        }

        if (can_arrive_the_end)
        {
            if (index == N)
            {
                double needV = (distances[N + 1] - distances[index]) / D2;
                double buyV = needV - V;
                if (buyV > 0)
                {
                    V = needV;
                    money += buyV * prices[index];
                }
                break;
            }
            else
            {
                int target = Find_next_Station(next_can_arrive,prices[index]);
                if (prices[target] > prices[index])
                {
                    //买油
                    double needV = (distances[N + 1] - distances[index])/D2;
                    double buyV = needV - V;
                    if (buyV > 0)
                    {
                        V = needV;
                        money += buyV * prices[index];
                    }
                    break;
                }
            }
        }

        //判断是否可达
        if (next_can_arrive.size() == 0)
        {
            cout << "No Solution";
            return 0;
        }
        //找到第一个最便宜的下一个车站
        int target = Find_next_Station(next_can_arrive,prices[index]);

        //买油
        if (prices[target] > prices[index])
        {
            double needV = (distances[target] - distances[index]) / D2;
            double buyV = maxV - V;
            if (buyV > 0)
            {
                money += buyV * prices[index];
            }
            index = target;
            V = maxV - needV;
        }
        else
        {
            double needV = (distances[target] - distances[index]) / D2;
            double buyV = needV - V;
            if (buyV > 0)
            {
                money += buyV * prices[index];
            }
            index = target;
        }
    }
    cout << fixed << setprecision(2) << money;
    return 0;
}
/*
87.75 13.03 5.75 7.29 3
22.10 7.38
24.21 6.81
82.08 6.96

105.95

*/