#include <iostream>
#include <vector>
using namespace std;
bool light[2000001];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        double a;
        int t;
        cin >> a >> t;
        for (int j = 1; j <= t; j++)
        {
            int node = (int)(a*j);
            if (light[node] == true)
            {
                light[node] = false;
            }
            else
            {
                light[node] = true;
            }
        }
    }
    for (int i = 1; i <= 2000000; i++)
    {
        if (light[i] == true)
        {
            cout << i;
            return 0;
        }
    }
}