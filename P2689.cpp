#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    int t;
    cin >> t;
    long long int x2 = x1 - x0;
    long long int y2 = y1 - y0;
    char targetx;
    char targety;
    if (x2 > 0)
    {
        targetx = 'E';
    }
    else
    {
        x2 = -x2;
        targetx = 'W';
    }
    if (y2 > 0)
    {
        targety = 'N';
    }
    else
    {
        y2 = -y2;
        targety = 'S';
    }
    int count = 0;
    int ans = 0;
    while (!(x2 == 0 && y2 == 0))
    {
        char direction;
        cin >> direction;
        count++;
        if (targetx == 'E' && x2 > 0 && direction == 'E')
        {
            x2--;
            ans++;
        }
        else if (targetx == 'W' && x2 > 0 && direction == 'W')
        {
            x2--;
            ans++;
        }
        if (targety == 'N' && y2 > 0 && direction == 'N')
        {
            y2--;
            ans++;
        }
        else if (targety == 'S' && direction == 'S' && y2 > 0)
        {
            y2--;
            ans++;
        }
        if ((x2 == 0 && y2 == 0) || count == t)
        {
            break;
        }
    }
    if (x2 == 0 && y2 == 0)
    {
        cout << ans;
        return 0;
    }
    cout << -1;
    return 0;
}
/*
2 1
2 1
10
E
W
S
E
W
E
W
S
N
S
*/