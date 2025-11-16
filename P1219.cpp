#include <iostream>
#include <vector>
using namespace std;

vector<int>ans;
int sum = 0;
vector<bool>diagonal;
vector<bool>reverse_diagonal;
void TraceBack(int x, vector<bool>y,int count)
{
    int n = y.size() - 1;
    for (int j = 1; j <= n; j++)
    {
        if (y[j] == false&& diagonal[x + j] == false&& reverse_diagonal[x - j + n] == false)
        {
            y[j] = true;
            diagonal[x + j] = true;
            reverse_diagonal[x - j + n] = true;

            ans[x] = j;
            if (count + 1 == n)
            {
                sum++;
                if (sum > 3)
                {
                    return;
                }
                else
                {
                    for (int i = 1; i <=n; i++)
                    {
                        printf("%d ", ans[i]);
                    }
                    printf("\n");
                }
            }
            TraceBack(x + 1, y ,count + 1);
            y[j] = false;
            diagonal[x + j] = false;
            reverse_diagonal[x - j + n] = false;
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    ans.resize(n + 1,-1);

    vector<bool>y(n + 1, false);
    diagonal.resize(2 * n + 1, false);
    reverse_diagonal.resize(2 * n + 1, false);
    TraceBack(1, y,0);

   
    printf("%d", sum);
    return 0;
}