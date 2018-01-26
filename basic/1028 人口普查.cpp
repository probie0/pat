#include<iostream>
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

//set会导致出生年月相同的人的排序出错，所以用vector
class People
{
public:
	string name;
	string birthday;
public:
	People(string n, string bd) : name(n), birthday(bd) {}
	bool operator<(const People &p)const
	{
		return birthday < p.birthday;
	}
};
int main()
{
	int N;
	cin >> N;
	string birthday, name;
	vector<People> vec_p; vec_p.reserve(N);
	for (int i = 0; i < N; i++)
	{
		cin >> name >> birthday;
		if (birthday <= "2014/09/06" && birthday >= "1814/09/06")
		{
			People p(name, birthday);
			vec_p.push_back(p);
		}
	}
	sort(vec_p.begin(), vec_p.end());
	if (!vec_p.empty())
		cout << vec_p.size() << " " << vec_p[0].name << " " << vec_p.back().name;
	else
		cout << 0 << "";
	system("pause");
	return 0;
}
