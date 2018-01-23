#include<cstdio>
#include<iostream>
#include<stdlib.h>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

int sort_descend(int n)
{
	string str_n = to_string(n);
	while (str_n.size() < 4)
		str_n = '0' + str_n;
	sort(str_n.rbegin(), str_n.rend());
	stringstream ss;
	ss << str_n;
	ss >> n;
	return n;
}
int sort_ascend(int n)
{
	string str_n = to_string(n);
	while (str_n.size() < 4)
		str_n = '0' + str_n;
	sort(str_n.begin(), str_n.end());
	stringstream ss;
	ss << str_n;
	ss >> n;
	return n;
}
int main()
{
	int n;
	cin >> n;
	do
	{
		int n_descend = sort_descend(n);
		int n_ascend = sort_ascend(n);
		n = n_descend - n_ascend;
		printf_s("%04d - %04d = %04d\n", n_descend, n_ascend, n);
	} while (n != 6174 && n != 0);
	system("pause");
	return 0;
}