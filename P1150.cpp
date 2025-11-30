#include <iostream>
using namespace std;
int main()
{
    int n;
    int k;
    cin >> n >> k;
    int count = 0;
    while (1)
    {
        count += n;
        n = n / k;
        if(n<k)
        {
            count+=n;
            break;
        }
    }
    cout << count;
    return 0;
}