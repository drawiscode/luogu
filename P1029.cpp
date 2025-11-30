/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    int y;
    cin >> x >> y;
    if (x > y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
    long long int count = 0;
    long long int mul = x * y;
    if(x==y)
    {
        cout<<1;
        return 0;
    }
    for (long long int i = 1; i <= sqrt(mul); i++)
    {
        if (mul % i == 0 && __gcd(i, mul / i) == x)
        {
            count += 2;
        }
    }
    cout << count;
    return 0;
}*/