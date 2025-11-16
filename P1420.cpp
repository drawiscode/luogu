#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int>data;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        data.emplace_back(d);
    }
    int ans = 1;
    int i = 0;
    int cur_ans = 1;

    while (i < n - 1)
    {
        if (data[i] + 1 == data[i + 1])
        {
            cur_ans++;
        }
        else
        {
            if (ans < cur_ans)
            {
                ans = cur_ans;
            }
            cur_ans = 1;
        }
        i++;
        if (i == n - 1)
        {
            if (ans < cur_ans)
            {
                ans = cur_ans;
            }
        }
    }
    cout << ans;
    return 0;
}