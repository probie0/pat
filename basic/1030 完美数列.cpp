#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;
//全局变量
long N; long p;
//已知m，求M
long find_M(long index_m, vector<long> &vec, int init_index_M)
{
	long  m = vec[index_m];
	long index_M = init_index_M;
	for (index_M; index_M < vec.size(); index_M++)  //m确定为所有数中最小的数
	{
		long M = vec[index_M];
		if (m*p < M)
			return --index_M;
	}
	return vec.size() - 1;        //M在数列末尾
}
int main()
{
	cin >> N >> p;
	vector<long> vec; vec.reserve(N);
	for (long i = 0; i < N; i++)
	{
		long temp; cin >> temp;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());
	long count = 0;
	long last_index_M = 0;
	for (long index_m = 0; index_m < vec.size(); index_m++)
	{
		long index_M = find_M(index_m, vec, last_index_M);
		long c = index_M - index_m + 1;
		if (count < c)
			count = c;
		if (count >  vec.size() - index_m)
			break;
		last_index_M = index_M;
	}
	cout << count;
	system("pause");
	return 0;
}
