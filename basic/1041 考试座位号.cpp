#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int  N;
	cin >> N;
	vector<string> num(N);
	vector<int> seat1(N);
	vector<int> seat2(N);
	for (int i = 0; i < N; i++)
		cin >> num[i] >> seat1[i] >> seat2[i];
	long long  M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int s1;
		cin >> s1;
		for (int j = 0; j < N; j++)
		{
			if (seat1[j] == s1)
				cout << num[j] << ' ' << seat2[j] << '\n';
		}
	}
	system("pause");
	return 0;
}