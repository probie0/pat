#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int N; char ch;
	cin >> N >> ch;
	if (N > 1)
	{
		int used = 1;
		int layer = 0;
		int k = 1;    //一行的字符个数
		int left;
		while (used < N)
		{
			layer++;
			k += 2;
			used += 2 * k;
		}
		used -= 2 * k;
		k -= 2;
		layer--;
		left = N - used;
		int line_up = 0;
		vector<string> vec1, vec2;
		for (int i = 0; i < layer; i++)
		{
			cout << string(line_up, ' ') << string(k, ch) << '\n';
			vec1.push_back(string(line_up, ' '));
			vec2.push_back(string(k, ch));
			k -= 2;
			line_up++;
		}
		cout << string(line_up, ' ') << string(k, ch) << '\n';
		for (int i = vec1.size() - 1; i >= 0; i--)
		{
			cout << vec1[i] << vec2[i] << '\n';
		}
		cout << left;
	}
	else
		cout << ch << '\n' << 0;
	
	system("pause");
	return 0;
}