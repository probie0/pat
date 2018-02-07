#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
#include<sstream>
#include<cctype>
using namespace std;
int findElement(const string &str, const vector<string> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (str == vec[i])
			return i;
	}
	return -1;
}
int str2int(const string &str)
{
	int out;
	stringstream ss;
	ss << str; ss >> out;
	return out;
}
int main()
{
	stringstream ss;
	vector<string> vec_l = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
	vector<string> vec_h = { "", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
	int N;
	cin >> N;
	cin.get();
	string input;
	for (int i = 0; i < N; i++)
	{
		getline(cin, input);
		if (isalpha(input[0]))       //»ðÐÇÎÄ
		{
			if (input.size() <= 4)
			{
				int n = findElement(input, vec_h);
				if (n != -1)
					ss << n * 13 << '\n';
				else
					ss << findElement(input, vec_l) << '\n';
			}
			if (input.size() > 4)
			{
				int n_h = findElement(input.substr(0,3), vec_h);
				int n_l = findElement(input.substr(4,3), vec_l);
				ss << n_h * 13 + n_l << '\n';
			}
		}
		else                    //Êý×Ö
		{
			int num = str2int(input);
			if (num < 13)
				ss << vec_l[num] << '\n';
			else
			{
				if (num % 13 == 0)
					ss << vec_h[num / 13] << '\n';
				else
					ss << vec_h[num / 13] << ' ' << vec_l[num % 13] << '\n';
			}
		}
	}
	cout << ss.str();
	system("pause");
	return 0;
}