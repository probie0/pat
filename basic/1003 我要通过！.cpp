#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool check(string str)
{
	int count_P = count(str.begin(), str.end(), 'P');
	int count_T = count(str.begin(), str.end(), 'T');
	if (count_P != 1 && count_T != 1)
		return false;
	int index_P = str.find_first_of('P');
	int index_T = str.find_first_of('T');
	if (index_P > index_T)
		return false;
	int len1 = index_P;
	int len2 = index_T - index_P - 1;
	int len3 = str.size() - index_T - 1;
	string str1 = str.substr(0, len1);
	string str2 = str.substr(index_P + 1, len2);
	string str3 = str.substr(index_T + 1, len3);
	if (str1.find_first_not_of('A')!=-1 || str2.find_first_not_of('A')!=-1 || str2.find_first_not_of('A')!=-1)
		return false;
	while (str2.size() > 1 && str3.size() - str1.size() >= 0)
	{
		str2.resize(str2.size() - 1);
		str3.resize(str3.size() - str1.size());
	}
	/*string new_str = str1 + 'P' +str2 + 'T' + str3;
    int	I = new_str.find("PAT");
	if (new_str.find("PAT") != -1)*/
	if (str2 == "A" && str1 == str3)
		return true;
	else
		return false;
	return false;
}

int main()
{
	int N;
	cin >> N;
	vector<bool> vec; vec.reserve(N);
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		if (check(str))
			vec.push_back(true);
		else
			vec.push_back(false);
	}
	for (auto e : vec)
	{
		if (e)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
	
	system("pause");
	return 0;
}