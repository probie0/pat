#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
	string str;
	int sum = 0;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		sum += int(str[i] - '0');
	}
	vector<string> vec = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
	vector<string> vec_result;
	string str_sum = to_string(sum);
	for (int i = 0; i < str_sum.size(); i++)
	{
		int index = int(str_sum[i] - '0');
		if (i == str_sum.size() - 1)
			cout << vec[index];
		else
			cout << vec[index] << " ";
	}

	//cout << sum << endl;
/*	
int x=0;
	for (int i = 0; i < log10(sum); i++)
	{
		x = sum % int(pow(10, i + 1)) / int(pow(10, i));
		vec_result.push_back(vec[x]);
	}
	
	for (int i = 0; i < vec_result.size(); i++)
	{
		int size = vec_result.size();
		cout << vec_result[size - i - 1] << " ";
	}
*/

	system("pause");
	return 0;
}