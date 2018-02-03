#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int main()
{
	long count_p = 0;
	long count_pa = 0;
	long count_pat = 0;
	char c = ' ';
	while (true)
	{
		c = cin.get();
		if (c == '\n')
			break;
		if (c == 'P')
			count_p++;
		else if (c == 'A')
			count_pa += count_p;
		else
			count_pat += count_pa;
	}
	cout << count_pat % 1000000007;
	system("pause");
	return 0;
}