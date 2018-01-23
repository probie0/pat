#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
class MoonCake
{
public:
	double price = 0; double storage = 0; double price_all = 0;
	bool operator < (const MoonCake &mc)
	{
		return this->price < mc.price;
	}
};
int main()
{
	int N = 0, D = 0;
	cin >> N >> D;
	vector<MoonCake> vec_mc; vec_mc.reserve(N);
	for (int i = 0; i < N; i++)
	{
		MoonCake mc;
		cin >> mc.storage;     //每种月饼总价格
		vec_mc.push_back(mc);
	}
	for (int i = 0; i < N; i++)
	{
		cin >> vec_mc[i].price_all;
		vec_mc[i].price = vec_mc[i].price_all / vec_mc[i].storage;
	}
	sort(vec_mc.rbegin(), vec_mc.rend());  //降序排列
	double profit = 0;
	for (int i = 0; i < vec_mc.size(); i++)
	{
		double storage = vec_mc[i].storage;
		double price = vec_mc[i].price;
		double price_all = vec_mc[i].price_all;
		if (D > storage)
		{
			D -= storage;
			profit += price_all;
		}
		else
		{
			profit += price * D;
			break;
		}
	}
	profit = round(profit * 100) / 100;
	printf("%.2lf", profit);
	system("pause");
	return 0;
}