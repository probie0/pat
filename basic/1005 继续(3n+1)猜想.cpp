#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;

//检查是否为“关键数”
bool check(const vector<vector<int>> &table, int n)
{
	for (int i = 0; i < table.size(); i++)
	{
		for (int j = 0; j < table[i].size(); j++)
		{
			if (table[i][j] == n)
				return false;
		}
	}
	return true;
}
int main()
{
	int N; int x;
	cin >> N;
	vector<int> vec; vec.reserve(N);
	vector<vector<int>> table; table.reserve(N);
	for (int i = 0; i < N; i++)
	{
		cin >> x; vec.push_back(x);
		while (x != 1)
		{
			if (x % 2 == 0)
				x /= 2;
			else
				x = (3 * x + 1) / 2;
			vector<int> vec_temp;
			vec_temp.push_back(x);
			table.push_back(vec_temp);
		}
	}
	vector<int> vec_result;
	for (int i = 0; i < N; i++)
	{
		if (check(table, vec[i]) == true)
			vec_result.push_back(vec[i]);
	}
	//降序排列
	sort(vec_result.rbegin(), vec_result.rend());
	for (int i = 0; i < vec_result.size()-1; i++)
		cout << vec_result[i] << " ";
	cout << vec_result[vec_result.size() - 1];

	system("pause");
	return 0;
}