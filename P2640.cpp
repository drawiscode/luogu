#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<bool>primes;
void Prime(int u)
{
    if (u == 1)
    {
        primes[u] = false;
        return;
    }
    for (int i = 2; i <= sqrt(u); i++)
    {
        if (u % i == 0)
        {
            primes[u] = false;
            return;
        }
    }
    primes[u] = true;
    return;
}
int main()
{
    int n, k;
    cin >> n >> k;
    primes.resize(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        Prime(i);
    }
    bool have = false;
    for (int i = 2; i + k <= n; i++)
    {
        if (primes[i] && primes[i + k])
        {
            have = true;
            cout << i << " " << i + k;
        }
    }
    if (!have)
    {
        cout << "empty";
    }
    return 0;
}