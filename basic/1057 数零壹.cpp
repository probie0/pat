#include<iostream>
#include<vector>
#include<cctype>
#include<string>
using namespace std;
int main()
{
	string str;
	getline(cin, str);
	int s = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (isalpha(str[i]))
		{
			s += (tolower(str[i]) - 'a' + 1);
		}
	}
	string bin;
	int q = s, r = 0; 
	int count1 = 0, count0 = 0;
	while (q != 0)
	{
		r = q % 2;
		q /= 2;
		if (r)
			count1++;
		else
			count0++;
	}
	cout << count0 << ' ' << count1;
	system("pause");
	return 0;
}