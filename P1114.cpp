#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int n;
    cin >> n;
    vector<int>datas(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> datas[i];
    }
    vector<int>sums(n + 1, 0);
    if (datas[1] == 1)
    {
        sums[1] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        sums[i] = sums[i - 1];
        if (datas[i] == 1)
        {
            sums[i]++;
        }
    }

    int ans = 0;

    for (int i = 0; i <= n; i++)
    {
        for (int j = i + ans; j <= n; j+=2)
        {
            if (sums[j] - sums[i] == (j - i) / 2)
            {
                ans = j - i;
            }
        }
    }

    cout << ans;
    return 0;
}

/*

10
0 1 0 0 0 1 1 0 1 1

*/