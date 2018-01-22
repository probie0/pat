#include<iostream>
#include<stdlib.h>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
using namespace std;

class Student
{
public:
	string name; string number; int grade;
	bool operator <(const Student &stu)const
	{
		return this->grade < stu.grade;
	}
};
int main()
{
	int N;
	cin >> N;
	Student stu;
	set<Student> stus;
	for (int i = 0; i < N; i++)
	{
		cin >> stu.name >> stu.number >> stu.grade;
		stus.insert(stu);
	}
	set<Student>::iterator it1 = stus.begin();
	set<Student>::reverse_iterator it2 = stus.rbegin();
	cout << it2->name << " " << it2->number << "\n";
	cout << it1->name << " " << it1->number << "\n";
	system("pause");
	return  0;
}