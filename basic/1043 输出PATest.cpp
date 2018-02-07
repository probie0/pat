#include<iostream>
#include<stdlib.h>
#include<string>
#include<map>
using namespace std;
bool check(char c, string &word)
{
	for (auto e : word)
	{
		if (c == e)
			return true;
	}
	return false;
}
int main()
{
	string word = "PATest";
	map<char, int> m;
	int count = 0;
	while (true)
	{
		char c = cin.get();
		if (c == '\n')
			break;
		if (check(c, word))
		{
			m[c]++;
			count++;
		}
	}
	while (count > 0)
	{
		for (int j = 0; j < 6; j++)
		{
			if (m[word[j]] > 0)
			{
				cout << word[j];
				count--;
				m[word[j]]--;
			}
		}
	}
	system("pause");
	return 0;
}