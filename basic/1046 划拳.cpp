#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int count_jia = 0, count_yi = 0;
	for (int i = 0; i < N; i++)
	{
		int jia_han, jia_hua, yi_han, yi_hua;
		cin >> jia_han >> jia_hua >> yi_han >> yi_hua;
		if (jia_hua == jia_han + yi_han && yi_hua != jia_han + yi_han)
			count_yi++;
		else if (yi_hua == jia_han + yi_han && jia_hua != jia_han + yi_han)
			count_jia++;
	}
	cout << count_jia << ' ' << count_yi;
	system("pause");
	return 0;
}