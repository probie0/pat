#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
	string str_A; int B;
	cin >> str_A >> B;
	vector<int> vec_A; vec_A.reserve(str_A.size());
	for (int i = 0; i < str_A.size(); i++)
	{
		int temp = int(str_A[i] - '0');
		vec_A.push_back(temp);
	}
	string Q = ""; int R = 0;
	int t = vec_A[0];
	int q = 0, r = 0;
	for (int i = 0; i < vec_A.size(); i++)
	{
		t = r * 10 + vec_A[i];
		r = t % B;
		q = int(floor(t / B)); Q += to_string(q);
	}
	R = r;
	if (Q[0] == '0' && Q.size() > 1)
		Q.erase(0, 1);
	cout << Q << " " << R;
	system("pause");
	return 0;
}