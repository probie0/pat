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
			People p; p.name = name; p.birthday = birthday;
			vec_p.push_back(p);
		}
	}
	if (!vec_p.empty())
	{
		auto pair = minmax_element(vec_p.begin(), vec_p.end());
		cout << vec_p.size() << " " << pair.first->name << " " << pair.second->name;
	}
	else
		cout << 0 << "";
	system("pause");
	return 0;
}
