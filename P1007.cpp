#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int l, n;
    cin >> l >> n;
    int mintime = 0;
    int maxtime = 0;
    for (int i = 0; i < n; i++)
    {
        int node;
        cin >> node;
        int thismin = min(l - node + 1, node);
        int thismax = max(l - node + 1, node);

        mintime = max(thismin, mintime);
        maxtime = max(thismax, maxtime);
    }
    cout << mintime << " " << maxtime;
    return 0;
}