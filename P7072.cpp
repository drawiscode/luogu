#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int n;
    int w;
    cin >> n >> w;
    vector<int>datas(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&datas[i]); 
    }
    vector<int>sort_datas;
    for (int i = 1; i <= n; i++)
    {
        bool insert = false;
        for (int j = 0; j < sort_datas.size(); j++)
        {
            if (datas[i] > sort_datas[j])
            {
                sort_datas.insert(sort_datas.begin() + j, datas[i]);
                insert = true;
                break;
            }
        }
        if (insert == false)
        {
            sort_datas.emplace_back(datas[i]);
        }
        int target = max(0,(i * w / 100) - 1);
        printf("%d ", sort_datas[target]);
        //cout << sort_datas[target] << " ";
    }
    return 0;
}