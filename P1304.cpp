#include <iostream>
#include <vector>
using namespace std;
vector<int>primes;
bool Prime(int num)
{
    for(int i=2;i*i<=num;i++)
    {
        if(num%i==0)
        {
            return false;
        }
    }
    return true;
}
void Oper(int num)
{
    for(int i=0;i<primes.size();i++)
    {
        int temp=num-primes[i];
        for(int j=0;j<primes.size();j++)
        {
            if(temp==primes[j])
            {
                cout<<num<<"="<<primes[i]<<"+"<<primes[j];
                return;
            }
        }
    }
}
int main()
{
    int N;
    cin>>N;
    for(int i=2;i<=N;i++)
    {
        if(Prime(i))
        {
            primes.emplace_back(i);
        }
    }
    for(int i=4;i<=N;i+=2)
    {
        Oper(i);
    }
    return 0;
}