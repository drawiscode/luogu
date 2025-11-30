#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{

    int n;
    cin >> n;
    vector<int>datas(n);
    for (int i = 0; i < n; i++)
    {
        cin >> datas[i];
    }
    int K = n;
    while (1)
    {
        unordered_map<int, int>mp;
        bool scc = true;
        for (int i = 0; i < n; i++)
        {
            mp[datas[i] % K]++;
            if (mp[datas[i] % K] != 1)
            {
                scc = false;
                break;
            }
        }
        if (scc)
        {
            break;
        }
        K++;
    }
    cout << K;
    return 0;
}
