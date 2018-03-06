#include<iostream>
#include<stdlib.h>
#include<cstdio>
using namespace std;
int main()
{
	int N = 0, D = 0;
	double e = 0;
	cin >> N >> e >> D;
	int count1 = 0, count2 = 0;
	for (int i = 0; i < N; i++)
	{
		int K;
		cin >> K;
		int d = 0;
		for (int j = 0; j < K; j++)
		{
			double E;
			cin >> E;
			if (E < e)
				d++;
		}
		if (d > K / 2 && K > D)
			count2++;
		else if (d > K / 2)
			count1++;
	}
	printf("%.1lf%% %.1lf%%", double(count1) / N * 100, double(count2) / N * 100);
	system("pause");
	return 0;
}