#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;
int main()
{
	double r1, p1, r2, p2;
	cin >> r1 >> p1 >> r2 >> p2;
	double a, b;
	a = r1*r2*cos(p1 + p2);
	b = r1*r2*sin(p1 + p2);
	if (abs(a) < 0.01)
		a = 0;
	if (abs(b) < 0.01)
		b = 0;
	printf("%.2lf", a);
	if (b >= 0)
	{
		cout << '+';
		printf("%.2lfi", b);
	}
	if(b < 0)
		printf("%.2lfi", b);
	system("pause");
	return 0;
}