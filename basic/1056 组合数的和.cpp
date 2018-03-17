#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<int> vec;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		vec.push_back(input);
	}
	int s = 0;
	for (int i = 0; i < N-1; i++)
	{
		for (int j = i + 1; j < vec.size(); j++)
			s += (vec[i] * 10 + vec[j] + vec[j] * 10 + vec[i]);
	}
	cout << s;
	system("pause");
	return 0;
}