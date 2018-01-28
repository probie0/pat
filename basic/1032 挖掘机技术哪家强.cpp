#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
int main()
{
	vector<int> vec_schoolScore(100000,0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int num;
		int score;
		cin >> num >> score;
		vec_schoolScore[num] += score;
	}
	int maxScore = 0, index = 0;
	for (int i = 1; i <= N; i++)
	{
		if (maxScore < vec_schoolScore[i])
		{
			index = i; maxScore = vec_schoolScore[i];
		}
	}
	cout << index << ' ' <<maxScore;
	
	system("pause");
	return 0;
}