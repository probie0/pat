#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<long> vec;
	vec.reserve(N);
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		if (max < a)
		{
			vec.push_back(a);
			max = a;
		}
		else
		{
			while (!vec.empty() && vec.back() > a)
				vec.pop_back();
		}
	}
	if (!vec.empty())
	{
		cout << vec.size() << '\n';
		for (int i = 0; i < vec.size() - 1; i++)
			cout << vec[i] << ' ';
		cout << vec.back();
	}
	else
		cout << 0 << '\n' << '\n';

	system("pause");
	return 0;
}