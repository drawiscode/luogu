#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//vector<int>lens;
vector<int>a;
int main()
{
    int n;
    cin>>n;
    //lens.resize(n);
    a.resize(5001,0);
    for(int i=0;i<n;i++)
    {
        int node;
        cin>>node;
        a[node]++;
    }
    long long int count=0;
    for(int i=1;i<=5000;i++)
    {
        if(a[i]==0)
        {
            continue;
        }
        for(int j=i;j<=5000;j++)
        {
            if(i+j>5000)
            {
                break;
            }
            if(a[j]==0)
            {
                continue;
            }
            else if(a[i+j]>1)
            {
                if(i==j&&a[i]>1)
                {
                    long long int add=1;
                    add*=a[i]*(a[i]-1)/2;
                    add*=a[i+j]*(a[i+j]-1)/2;
                    count+=add;
                    count=count%1000000007;
                }
                else
                {
                    long long int add=1;
                    add*=a[i]*a[j];
                    add*=a[i+j]*(a[i+j]-1)/2;
                    count+=add;
                    count=count%1000000007;
                }
            }
        }

    }
    cout<<count;
    return 0;
}
/*
7
1 1 1 1 2 2 2

10
1
1
2
2
3
3
4
4
5
5

1 2 3 4 5
2 2 2 2 2

2 3 4 5
1 4 5 8 

*/
