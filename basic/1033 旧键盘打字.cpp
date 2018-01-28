#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
#include<cctype>
#include<algorithm>
using namespace std;
bool isBroken(string &str_loss, char ch)
{
	for (int j = 0; j < str_loss.size(); j++)
	{
		if (str_loss[j] == toupper(ch))
			return true;
	}
	return false;
}
int main()
{
	string str_loss, str1;
	getline(cin, str_loss);
	getline(cin, str1);
	vector<char> vec_result;
	vec_result.reserve(str1.size());
	if (str_loss.end() == find(str_loss.begin(), str_loss.end(), '+')) //ÉÏµµ¼üÃ»»µ
	{
		for (int i = 0; i < str1.size(); i++)
		{
			if (!isBroken(str_loss, str1[i]))
				vec_result.push_back(str1[i]);
		}
	}
	else
	{
		for (int i = 0; i < str1.size(); i++)
		{
			if (!isBroken(str_loss, str1[i]) && !isupper(str1[i]))
				vec_result.push_back(str1[i]);
		}
	}
	if (!vec_result.empty())
	{
		for (auto e : vec_result)
			cout << e;
	}
	else
		cout << '\n';

	system("pause");
	return 0;
}