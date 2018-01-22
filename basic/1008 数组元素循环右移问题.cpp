#include<iostream>
#include<stdlib.h>
#include<deque>
#include<algorithm>
using namespace std;

int main()
{
	int N = 0, M = 0;
	cin >> N >> M;
	if (M >= N)          //若移动的个数超过总的元素个数
		M = M % N;
	deque<int> deq;
	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		cin >> temp;
		deq.push_back(temp);
	}
	deque<int> deq_temp;
	for (int i = 0; i < M; i++)
	{
		deq_temp.push_front(deq.back());
		if(deq.size() > 0)
			deq.pop_back();
	}
	for (int i = 0; i < M; i++)
	{
		deq.push_front(deq_temp.back());
		deq_temp.pop_back();
	}
	for (int i = 0; i < deq.size()-1; i++)
		cout << deq[i] << " ";
	cout << deq[deq.size() - 1];
	system("pause");
	return 0;
}