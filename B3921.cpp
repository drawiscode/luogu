#include <iostream>
using namespace std;
int main()
{
    int x;
    int y;
    cin >> x >> y;
    int ans = (x + y) % 7;
    if (ans == 0)
    {
        ans = 7;
    }
    cout << ans;
    return 0;
}