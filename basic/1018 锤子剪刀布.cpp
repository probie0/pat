#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string>
#include<map>
using namespace std; 

int isWin(char ch_jia, char ch_yi)
{
	if (ch_jia == 'C' && ch_yi == 'J')
		return 1;
	else if (ch_jia == 'J' && ch_yi == 'B')
		return 1;
	else if (ch_jia == 'B' && ch_yi == 'C')
		return 1;
	else if (ch_jia == ch_yi)
		return 0;
	else 
		return -1;
}
void getMax(map<char, int> &m, int &max, char &gest)
{
	max = 0; gest = 'Z';
	for (map<char, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		if (it->second > max)
		{
			max = it->second;
			gest = it->first;
		}
		if (it->second == max)
		{
			if (it->first < gest)
				gest = it->first;
		}
	}
}
int main()
{
	int N; char ch_jia, ch_yi;
	int n_jia = 0, n_yi = 0, n_ping = 0;
	map<char, int> m_jia, m_yi;
	m_jia['C'] = 0; m_jia['B'] = 0; m_jia['J'] = 0;
	m_yi['C'] = 0; m_yi['B'] = 0; m_yi['J'] = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> ch_jia >> ch_yi;
		if (isWin(ch_jia, ch_yi) == 1)
		{
			n_jia++; m_jia[ch_jia]++;
		}
		else if (isWin(ch_jia, ch_yi) == -1)
		{
			n_yi++; m_yi[ch_yi]++;
		}
		else
			n_ping++;
	}
	cout << n_jia << " " << n_ping << " " << n_yi << '\n';
	cout << n_yi << " " << n_ping << " " << n_jia << '\n';
	int max_jia = 0, max_yi = 0; 
	char gest_jia = 'Z', gest_yi = 'Z';
	getMax(m_jia, max_jia, gest_jia);
	getMax(m_yi, max_yi, gest_yi);
	cout << gest_jia << " " << gest_yi << '\n';
	system("pause");
	return 0;
}