#include <iostream>
#include <vector>
using namespace std;
vector<int>datas;
int main()
{
    int n;
    cin >> n;
    datas.resize(n+1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> datas[i];
    }
    vector<int>ans(n+1, 0);
    ans[0] = 0;
    ans[1] = datas[1];
    for (int i = 1; i <= n; i++)
    {
        ans[i] = ans[i - 1] + datas[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int left;
        int right;
        cin >> left >> right;
        cout << ans[right] - ans[left-1]  << endl;
    }
    return 0;
}