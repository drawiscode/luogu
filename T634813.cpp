#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    long long int x;
    long long int y;
    cin >> n >> x >> y;
    vector<long long int>a(n);
    vector<long long int>b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    int index = 0;
    while (index < n)
    {
        if (x < a[index] || x>y)
        {
            break;
        }
        else
        {
            x = x - a[index] + b[index];
        }
        index++;
    }
    cout << x;
    return 0;
}