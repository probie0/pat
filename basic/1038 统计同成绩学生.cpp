#include<vector>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<int> vec(101, 0);
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		vec[temp]++;
	}
	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int score;
		cin >> score;
		if (i == K - 1)
			cout << vec[score];
		else
			cout << vec[score] << ' ';
	}
	system("pause");
	return 0;
}