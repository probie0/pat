#include<iostream>
using namespace std;

int main()
{
	int count;
	long  a, b, c;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> a >> b >> c;
		if (a + b > c)
		{
			cout << "Case #" << i + 1 << ": true" << endl;
		}
		else
		{
			cout << "Case #" << i + 1 << ": false" << endl;
		}
	}
}