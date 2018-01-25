#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;

class Node
{
public:
	int addr; int data; int next_add;
};
int main()
{
	int addr_first, N, K;
	cin >> addr_first >> N >> K;
	list<Node> li1; 
	for (int i = 0; i < N; i++)
	{
		Node nd;
		cin >> nd.addr >> nd.data >> nd.next_add;
		li1.push_back(nd);
	}
	vector<Node> vec1; vec1.reserve(N);
	int next_addr = addr_first;

	int size = li1.size();
	for (int i = 0; i < size; i++)
	{
		for (list<Node>::iterator it_j = li1.begin(); it_j != li1.end(); )
		{
			int addr = it_j->addr;
			if (next_addr == addr)
			{
				vec1.push_back(*it_j);
				next_addr = it_j->next_add;
				li1.erase(it_j++);
				break;
			}
			else
				it_j++;
		}
	}
	if (K > 1)
	{
		vector<Node>::iterator it1 = vec1.begin();
		for (vector<Node>::iterator it = vec1.begin(); it != vec1.end(); it++)
		{
			if (distance(it1, it) + 1 == K)
			{
				reverse(it1, it + 1); it1 = it + 1;
			}
		}
		for (int i = 0; i < vec1.size() - 1; i++)
			vec1[i].next_add = vec1[i + 1].addr;
		vec1[vec1.size() - 1].next_add = -1;
	}
	int i = 0;
	for (i; i < vec1.size() - 1; i++)
		printf("%05d %d %05d\n", vec1[i].addr, vec1[i].data, vec1[i].next_add);
	printf("%05d %d %d\n", vec1[i].addr, vec1[i].data, -1);

	system("pause");
	return 0;
}