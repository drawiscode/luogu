#include <iostream>
#include <vector>
using namespace std;
bool Oper(int n,int k)
{
    int num1;
    int num2;
    int num3;
    num1=n/100;
    num3=n%1000;
    num2=(n/10)%1000;
    if(num1%k==0&&num2%k==0&&num3%k==0)
    {
        return true;
    
    }
    return false;

}
int main()
{
    int K;
    cin>>K;
    int count=0;
    for(int i=10000;i<=30000;i++)
    {
        if(Oper(i,K))
        {
            count++;
            printf("%d\n",i);
        }
    }
    if(count==0)
    {
        cout<<"No";
    }
    return 0;
}