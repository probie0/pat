#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>
using namespace std;
int main()
{
	vector<int> vec_weight{ 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	vector<char> vec_M{ '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };
	int N;
	cin >> N;
	string str;
	vector<string> vec; vec.reserve(N);
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		vec.push_back(str);
	}
	bool flag = true;
	for(int i = 0; i < N; i++)
	{
		str = vec[i];
		int sum = 0;
		for (int i = 0; i < 17; i++)
		{
			sum += int(str[i] - '0') * vec_weight[i];
		}
		char checkCode = vec_M[sum % 11];
		if (checkCode != str[17])
		{
			cout << str << '\n'; flag = false;
		}
	}
	if (flag == true)
		cout << "All passed";

	system("pause");
	return 0;
}