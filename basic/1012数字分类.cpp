#include<iostream>
#include<vector>
#include <iomanip>
#include<math.h>
using namespace std;

int main()
{
	int count;
	cin >> count;
	int x;
	vector<int> vec;
	int a1{}, a2{}, a3{}, a5{};
	double a4{};
	for (int i = 0; i < count; i++)
	{
		cin >> x;
		vec.push_back(x);
	}

	for (int i = 0; i < count; i++)
	{
		int e = vec[i];
		if (e % 5 == 0)
		{
			if (e % 2 == 0)
			{
				a1 += e;
			}
		}
	}

	bool flag = true;
	for (int i = 0; i < count; i++)
	{
		int e = vec[i];
		if (e % 5 == 1 && flag == true)
		{
			a2 += e;
			flag = false;
		}
		else if (e%5 == 1 && flag == false)
		{
			a2 -= e;
			flag = true;
		}
	}

	for (int i = 0; i < count; i++)
	{
		int e = vec[i];
		if (e % 5 == 2)
		{
			a3 += 1;
		}
	}

	int num_a4 = 0;
	for (int i = 0; i < count; i++)
	{
		
		int e = vec[i];
		if (e % 5 == 3)
		{
			a4 += e;
			num_a4++;
		}
	}

	if (num_a4 != 0)
		a4 /= num_a4;

	a4 = round(a4 * 10) / 10;

	for (int i = 0; i < count; i++)
	{
		int e = vec[i];
		if (e % 5 == 4 && e > a5)
		{
			a5 = e;
		}
	}

	if (a1 == 0)
		cout << "N ";
	else
		cout << a1 << " ";

	if (a2 == 0)
		cout << "N ";
	else
		cout << a2 << " ";

	if (a3 == 0)
		cout << "N ";
	else
		cout << a3 << " ";

	if (a4 == 0)
		cout << "N ";
	else
		cout << fixed << setprecision(1) << a4 << " ";

	if (a5 == 0)
		cout << "N";
	else
		cout << a5;


	

	return 0;
}