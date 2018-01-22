#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	string str; vector<string> vec;
	getline(cin, str);
	str = ' ' + str + ' ';
	int index1 = 0, index2 = 0;
	for (int i = 2; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			index2 = i;
			int len = index2 - index1 - 1;
			vec.push_back(str.substr(index1+1, len));
			index1 = index2;
		}
	}
	vector<string>::reverse_iterator it;
	for (it = vec.rbegin(); it != vec.rend()-1; it++)
		cout << *it << " ";
	cout << *it;
	
	system("pause");
	return 0;
}