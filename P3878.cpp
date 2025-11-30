#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
using namespace std;
int ans;
int get(vector<int>&money)
{
	int n = money.size();
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i< n / 2; i++)
	{
		sum1 += money[i];
	}
	for (int j = n / 2; j < n; j++)
	{
		sum2 += money[j];
	}
	return abs(sum1 - sum2);
}
void SA(vector<int>&money)
{
	int n = money.size();
	double T1 = 1000;
	double T2 = 1e-10;
	double changeT = 0.933;
	for (double T = T1; T >= T2; T *= changeT)
	{
		int x1 = rand() % n;
		int x2 = rand() % n;
		int temp1 = money[x1];
		int temp2 = money[x2];
		money[x1] = temp2;
		money[x2] = temp1;
		int sum = get(money);
		if (ans > sum)
		{
			ans = sum;
		}
		else if (exp((double)(ans-sum)/T)<((double)rand()/(double)RAND_MAX))
		{
			money[x1] = temp1;
			money[x2] = temp2;
		}
	}
}
int main()
{
	int T;
	cin >> T;
	int count = 0;
	while (count < T)
	{
		int n;
		cin >> n;
		vector<int>money(n);
		ans = INT32_MAX;
		for (int i = 0; i < n; i++)
		{
			cin >> money[i];
		}
		int x = 0;
		while (x < 1000)
		{
			SA(money);
			x++;
		}
		count++;
		cout << ans << endl;
	}
	return 0;
}
/*
1
3
2 2 4
*/