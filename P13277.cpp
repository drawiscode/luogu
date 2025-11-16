#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<int>datas(n);
    int maxval = -1;
    for (int i = 0; i < n; i++)
    {
        int x, y, val;
        cin >> val >> x >> y;
        if (x == 1 && y == 1)
        {
            continue;;
        }
        if (x == 1)
        {
            val -= k1;
        }
        else if (y == 1)
        {
            val -= k2;
        }
        maxval = max(maxval, val);
    }
    cout << maxval;
    return 0;
}