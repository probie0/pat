#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stdlib.h>
using namespace std;

class Student
{
public:
	long number; int morality; int talent; int score; int level;
	bool operator <(const Student &stu)const
	{
		if (level == stu.level)
		{
			if (score == stu.score)
			{
				if (morality == stu.morality)
					return number > stu.number;
				else
					return morality < stu.morality;
			}
			else
				return score < stu.score;
		}
		else
			return level > stu.level;
	}
};
void getLevel(Student &stu, int H, int L)
{
	long number = stu.number; int morality = stu.morality; int talent = stu.talent;
	int score = stu.score; 
	if (morality < L || talent < L)
		stu.level = -1;
	else
	{
		if (morality >= H && talent >= H)
			stu.level = 1;
		else if (morality >= H && talent < H)
			stu.level = 2;
		else if (morality >= talent && morality < H && talent < H)
			stu.level = 3;
		else
			stu.level = 4;
	}
}
int main()
{
	set<Student> stus; set<Student>::reverse_iterator it;
	long N = 0;  int L = 0; int H = 0; Student stu;
	cin >> N >> L >> H;
	for (int i = 0; i < N; i++)
	{
		cin >> stu.number >> stu.morality >> stu.talent;
		stu.score = stu.morality + stu.talent;
		getLevel(stu, H, L);
		if(stu.level > 0)
			stus.insert(stu);
	}
	cout << stus.size() << "\n";
	for (it = stus.rbegin(); it != stus.rend(); it++)
	{
		cout << it->number << " " << it->morality << " " << it->talent << "\n";
	}
	system("pause");
	return 0;
}