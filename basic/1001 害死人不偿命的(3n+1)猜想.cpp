#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int count = 0;
	while (n != 1)
	{
		if (n % 2 == 0)
		{
			n /= 2;
		}
		else
		{
			n = (3 * n + 1) / 2;
		}
		count++;
	}
	cout << count;

	system("pause");
	return 0;
}