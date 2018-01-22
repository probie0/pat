#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string>
#include <iomanip>
#include<cctype>
using namespace std;

int main()
{
	string str1, str2, str3, str4;
	cin >> str1 >> str2 >> str3 >> str4;

	int index1 = 0, index2 = 0, index3 = 0;
	char  char1{}, char2{}, char3{};
	for (int i = 0; i < str1.size() && i < str2.size(); i++)
	{
		if (str1[i] == str2[i] && isupper(str1[i]) && isupper(str2[i]))
		{
			index1 = i;
			char1 = str1[i];
			break;
		}
	}

	for (int i = index1+1; i < str1.size() && i < str2.size(); i++)
	{
		if (str1[i] == str2[i])
		{
			index2 = i;
			char2 = str1[i];
			break;
		}
	}

	for (int i = 0; i < str3.size() && i < str4.size(); i++)
	{
		if (str3[i] == str4[i] && isalpha(str3[i]) && isalpha(str4[i]))
		{
			index3 = i;
			char3 = str3[i];
			break;
		}
	}

	string day{};
	int hour{}, minute{};
	if (char1 == 'A')
		day = "MON";
	else if (char1 == 'B')
		day = "TUE";
	else if (char1 == 'C')
		day = "WED";
	else if (char1 == 'D')
		day = "THU";
	else if (char1 == 'E')
		day = "FRI";
	else if (char1 == 'F')
		day = "SAT";
	else if (char1 == 'G')
		day = "SUN";

	vector<char> vec = { '1', '2', '3', '4', '5', '6', '7',
	'8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N'};
	for (int i = 1; i < vec.size(); i++)
	{
		if (char2 == vec[i])
		{
			hour = i+1;
		}
	}

	minute = index3;

	cout << day + " " << setw(2) << setfill('0') << hour 
		<< ":" << setw(2) << setfill('0') << minute << endl;;

	system("pause");
	return 0;
}