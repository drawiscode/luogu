#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int count = 0;
    for (int i = 0; i <= sqrt(n); i++)
    {
        for (int j = 0; j <= sqrt(n); j++)
        {
            for (int k = 0; k <= sqrt(n); k++)
            {
                int less = n - i * i - j * j - k * k;
                if ((int)sqrt(less) * (int)sqrt(less) == less && less >= 0)
                {
                    count++;
                    continue;
                }
            }
        }
    }
    cout << count;
    return 0;
}