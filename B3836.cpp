#include <iostream>
using namespace std;
int main()
{
    int x;
    int y;
    int z;
    cin >> x >> y >> z;
    int n;
    int m;
    cin >> n >> m;
    long long int count = 0;
    for (int i = 0; i <= n / x; i++)
    {
        for (int j = 0; j <= n / y; j++)
        {
            int left_money = n - i * x - j * y;
            if (left_money < 0)
            {
                continue;
            }
            int small_chilkens = left_money * z;
            if (small_chilkens + i + j == m)
            {
                count++;
            }
        }
    }
    cout << count;
    return 0;
}