#include<iostream>
#include<stdlib.h>
#include<vector>
#include<cctype>
using namespace std;
int main()
{
	vector<int> vec(128, 0);
	while (true)
	{
		char c = cin.get();
		if (c == '\n')
			break;
		if(isalpha(c))
			vec[int(tolower(c))]++;
	}
	int c_max = 0;  //字符（下标）
	int count = 0;  //字符出现的次数
	for (size_t i = 97; i < 123; i++)  //小写字母范围97-123
	{
		if (count < vec[i])
		{
			c_max = i;
			count = vec[i];
		}
	}
	cout << char(c_max) << ' ' << count;
	system("pause");
	return 0;
}