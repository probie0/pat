#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

int main()
{
	string str;
	cin >> str;
	if (str.size() == 2)
		str = '0' + str;
	else if (str.size() == 1)
		str = "00" + str;
	int baiwei = int(str[0] - '0');
	int shiwei = int(str[1] - '0');
	int gewei = int(str[2] - '0');

	for (int j = 0; j < baiwei; j++)
		cout << "B";
	for (int j = 0; j < shiwei; j++)
		cout << "S";
	for (int j = 1; j <= gewei; j++)
		cout << j;

	system("pause");
	return 0;
}