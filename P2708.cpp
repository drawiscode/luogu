#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string coins;
    cin >> coins;
    vector<char>coin;
    int pre = coins[0];
    for (int i = 1; i < coins.size(); i++)
    {
        if (coins[i] != pre)
        {
            coin.emplace_back(pre);
            pre = coins[i];
        }
    }
    coin.emplace_back(pre);
    int n = coin.size();
    if (coin[n - 1] == '1')
    {
        cout << n - 1;
    }
    else
    {
        cout << n;
    }
    return 0;
}