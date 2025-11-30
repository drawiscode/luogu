#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int>datas;
vector<unordered_map<int, int>>primes_map;
vector<bool>is_primes;
vector<int>primes;
vector<bool>Can;
void Print()
{
    return;
}
void Cal_Primes()
{
    int n = is_primes.size()-1;
    for (int i = 2; i <= 30000; i++)
    {
        if (is_primes[i] == true)
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                is_primes[j] = false;
            }
            primes.emplace_back(i);
        }
    }
}
void Cal(int u)
{
    int node = u;
    u = datas[u];
    while (1)
    {
        if (u == 1)
        {
            break;
        }
        bool have = false;
        for (int i = 0; i < primes.size(); i++)
        {
            if (u % primes[i] == 0)
            {
                //cout << primes[i] << endl;

                primes_map[node][primes[i]]++;
                u = u / primes[i];
                have = true;
                break;
            }
        }
        if (have == false && u > 30000)
        {
            Can[node] = false;
        }
    }
   
}
int main()
{
    int n;
    int m1, m2;
    cin >> n >> m1 >> m2;


    datas.resize(n + 1);
    primes_map.resize(n + 1);
    Can.resize(n,true);

    for (int i = 0; i < n; i++)
    {
        cin >> datas[i];
        //maxV = max(maxV, datas[i]);
    }
    datas[n] = m1;

    is_primes.resize(30001,true);
    is_primes[0] = false;
    is_primes[1] = false;
    Cal_Primes();

    if (m1 == 1)
    {
        int ans = datas[0];
        cout << 0;
        return 0;
    }

    for (int i = 0; i <= n; i++)
    {
        Cal(i);
    }

    for (auto node = primes_map[n].begin(); node != primes_map[n].end(); node++)
    {
        node->second *= m2;
    }

    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (Can[i] == false)
        {
            continue;
        }
        int this_ans = -1;
        for (auto node = primes_map[n].begin(); node != primes_map[n].end(); node++)
        {
            int cur_prime = node->first;
            if (primes_map[i].find(cur_prime) == primes_map[i].end())
            {
                this_ans = -1;
                break;
            }
            else
            {
                int count = primes_map[i][cur_prime];
                int need_count = node->second;
                if (need_count % count == 0)
                {
                    this_ans = max(this_ans, need_count / count);
                }
                else
                {
                    this_ans = max(this_ans, 1 + (need_count / count));
                }
            }
        }
        if (this_ans != -1)
        {
            if (ans == -1)
            {
                ans = this_ans;
            }
            else
            {
                ans = min(ans, this_ans);
            }
        }
    }
    cout << ans;
    return 0;
}
/*
1
1 1
645855438 

*/