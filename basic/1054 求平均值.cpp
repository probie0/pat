#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
#include<cctype>
#include<sstream>
#include<cstdio>
using namespace std;
bool isNum(string str)
{
	int dot_count = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]) && str[i] != '.' && str[i] != '-')
			return false;
		else if (str[i] == '.')
			dot_count++;
		else if (str[i] == '-')          //如果负号出现在其他位置，则不是数字
		{
			if (i != 0)
				return false;
		}
	}
	if (dot_count <= 1)
		return true;
	else
		return false;
}
bool check(string str)       //检查小数点后的位数
{
	int idx = str.size() - 1;   //小数点位置
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '.')
		{
			idx = i; break;
		}
	}
	int len= str.size() - idx - 1;
	if (len > 2)
		return false;
	else
		return true;
}
int main()
{
	int N = 0;
	cin >> N;
	int cnt = 0;
	double sum_all = 0;
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		if (!isNum(input))
			cout << "ERROR: " << input << " is not a legal number\n";
		else
		{
			double num = 0;
			stringstream ss;
			ss << input; ss >> num;
			if (num < -1000 || num > 1000 || check(input) == false)
				cout << "ERROR: " << input << " is not a legal number\n";
			else
			{
				sum_all += num; cnt++;
			}
		}
	}
	double aver = sum_all / cnt;
	if (cnt == 1)
		printf("The average of 1 number is %.2lf", aver);
	else if (cnt == 0)
		printf("The average of 0 numbers is Undefined");
	else 
		printf("The average of %d numbers is %.2lf", cnt, aver);
	system("pause");
	return 0;
}