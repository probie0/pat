#include<iostream>
#include<stdlib.h>
#include<string>
#include<cmath>
using namespace std;

int main()
{
	double N;
	char c;
	cin >> N >> c;
	int length = int(N);
	int width = int(round(N / 2));
	cout << string(length, c);
	cout << '\n';
	for (int i = 0; i < width - 2; i++)
		cout << c + string(length - 2, ' ') + c << '\n';
	cout << string(length, c);
	system("pause");
	return 0;
}