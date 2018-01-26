#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	double c1, c2;
	cin >> c1 >> c2;
	double t = round((c2 - c1) / 100);
	int h = floor(t / 3600);
	int m = floor((t - h * 3600) / 60);
	int s = round(t - h * 3600 - m * 60);
	printf("%02d:%02d:%02d", h, m, s);

	system("pause");
	return 0;
}