#include<iostream>
#include<stdlib.h>
#include<vector>
#include<cmath>
using namespace std;

bool isPrime(int x)
{
	if (x == 2)
		return true;
	for (int i = 2; i < sqrt(x) + 1; i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}
void getPrimes(int n, vector<int> &vec)
{
	for (int x = 2; x <= n; x++)
	{
		if (isPrime(x))
			vec.push_back(x);
	}
}
int main()
{
	int n;
	cin >> n;
	vector<int> vec; vec.reserve(80000);
	getPrimes(n, vec);
	int count_pairs = 0;
	for (int i = 0; i < vec.size()-1; i++)
	{
		if (vec[i + 1] - vec[i] == 2)
			count_pairs++;
	}
	cout << count_pairs;
	system("pause");
	return 0;
}