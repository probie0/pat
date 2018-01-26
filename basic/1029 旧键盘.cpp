#include<string>
#include<stdlib.h>
#include<iostream>
#include<cctype>
#include<algorithm>
using namespace std;

void str_toUpper(string &str)
{
	for (int i = 0; i < str.size(); i++)
		str[i] = toupper(str[i]);
}
void strUnique(string &str)
{
	for (int i = str.size() - 1; i >= 0; i--)
	{
		for (int j = str.size() - 1; j >= 0; j--)
		{
			if (str[i] == str[j] && i != j)
				str.erase(i, 1);
		}
	}
}
int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	str_toUpper(str1); str_toUpper(str2);
	strUnique(str1); strUnique(str2);
	string result = "";
	for (int i = 0; i < str1.size(); i++)
	{
		if (str2.end() == find(str2.begin(), str2.end(), str1[i]))
			result += str1[i];
	}
	cout << result;
	system("pause");
	return 0;
}