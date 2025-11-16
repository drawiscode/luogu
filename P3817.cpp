#include <iostream>
#include <vector>
/*
5 23
42 2 23 23 36
*/
using namespace std;
int main()
{
    int n;
    int max;
    cin >> n >> max;
    vector<long long int>data(n);
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }
    long long int eat = 0;
    if (data[0] > max)
    {
        eat = data[0]-max;
        data[0] = max;
    }
    for (int i = 1; i < n; i++)
    {
        if (data[i] + data[i - 1] > max)
        {
            eat+=data[i];
            eat+=data[i-1];
            eat-=max;
            data[i]-=data[i];
            data[i]-=data[i-1];
            data[i]+=max;
        }
    }
    printf("%ld", eat);
    return 0;
}