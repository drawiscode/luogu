#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        int j = 1;
        while (1)
        {
            if (i * j == n)
            {
                count++;
                break;
            }
            else if (i * j > n)
            {
                break;
            }
            j++;
        }
    }
    cout << count;
    return 0;
}