#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;

int main()
{
	char da, db; string a, b;
	long na = 0, nb = 0; string  str_pa = "", str_pb = "";
	cin >> a >> da;
	cin >> b >> db;
	na = count(a.begin(), a.end(), da);
	nb = count(b.begin(), b.end(), db);
	for (int i = 0; i < na; i++)
		str_pa += da;
	for (int i = 0; i < nb; i++)
		str_pb += db;
	long pa, pb;
	stringstream ssa, ssb;
	if (str_pa != "")
	{
		ssa << str_pa; ssa >> pa;
	}
	else
		pa = 0;

	if (str_pb != "")
	{
		ssb << str_pb; ssb >> pb;
	}
	else
		pb = 0;
	cout << pa + pb;
	system("pause");
	return 0;
}