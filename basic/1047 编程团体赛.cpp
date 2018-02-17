#include<iostream>
#include<stdlib.h>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<int> vec_teams(1001,0);
	for (int i = 0; i < N; i++)
	{
		int teamNum, memberNum, score;
		scanf_s("%d-%d %d", &teamNum, &memberNum, &score);
		vec_teams[teamNum] += score;
	}
	int index_max = 0, max = 0;
	for (int i = 0; i < 1001; i++)
	{
		if (vec_teams[i] > max)
		{
			max = vec_teams[i];
			index_max = i;
		}
	}
	cout << index_max << ' ' << max;
	system("pause");
	return 0;
}