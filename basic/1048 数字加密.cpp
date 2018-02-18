#include<iostream>
#include<stdlib.h>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string a, b;
	cin >> a >> b;
	string result;
	result.reserve(b.size());
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int size_big, size_small;
	if (a.size() > b.size())
	{
		size_big = a.size();
		size_small = b.size();
		b.append((a.size() - b.size()), '0');
	}
	else
	{
		size_big = b.size();
		size_small = a.size();
		a.append(b.size() - a.size(), '0');
	}
	for (int i = 0; i < size_big; i++)
	{
		if ((i+1) % 2 != 0)
		{
			int s = (int(a[i] - '0') + int(b[i] - '0')) % 13;
			if (s < 10)
				result.append(to_string(s));
			else if (s == 10)
				result += 'J';
			else if (s == 11)
				result += 'Q';
			else if (s == 12)
				result += 'K';
		}
		else 
		{
			int diff = int(b[i] - '0') - int(a[i] - '0');
			if (diff < 0)
				diff += 10;
			result.append(to_string(diff));
		}
	}
	reverse(result.begin(), result.end());
	cout << result;

	system("pause");
	return 0;
}