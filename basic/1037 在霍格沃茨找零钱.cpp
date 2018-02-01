#include<iostream>
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<iterator>
#include<sstream>
using namespace std;
struct FooMoney
{
	long  galleon; long  sickle; long  knut;
};
FooMoney mySubstract(FooMoney m2, FooMoney m1)
{
	FooMoney result;
	if (m2.knut >= m1.knut)
		result.knut = m2.knut - m1.knut;
	else
	{
		m2.sickle--;
		result.knut = m2.knut + 29 - m1.knut;
	}
	if (m2.sickle >= m1.sickle)
		result.sickle = m2.sickle - m1.sickle;
	else
	{
		m2.galleon--;
		result.sickle = m2.sickle + 17 - m1.sickle;
	}
	result.galleon = m2.galleon - m1.galleon;
	return result;
}
string FooMoneyToString(FooMoney &m)
{
	string out = to_string(m.galleon) + '.' + to_string(m.sickle) 
		+ '.' + to_string(m.knut);
	return out;
}
long  str2long (string &str)
{
	long  out;
	stringstream ss;
	ss << str; ss >> out;
	return out;
}
FooMoney str2FooMoney(string &str)
{
	string str_galleon, str_sickle, str_knut;
	string::iterator it1 = find(str.begin(), str.end(), '.');
	string::iterator it2 = find(it1 + 1, str.end(), '.');
	copy(str.begin(), it1, back_inserter(str_galleon));
	copy(it1 + 1, it2, back_inserter(str_sickle));
	copy(it2 + 1, str.end(), back_inserter(str_knut));
	FooMoney m;
	m.galleon = str2long(str_galleon);
	m.sickle = str2long(str_sickle);
	m.knut = str2long(str_knut);
	return m;
}
int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	FooMoney result;
	string str_result;
	FooMoney m1 = str2FooMoney(str1);
	FooMoney m2 = str2FooMoney(str2);
	if (str2 >= str1)
	{
		result = mySubstract(m2, m1);
		str_result = FooMoneyToString(result);
	}
	else
	{
		result = mySubstract(m1, m2);
		str_result = '-' + FooMoneyToString(result);
	}
	cout << str_result;
	system("pause");
	return 0;
}