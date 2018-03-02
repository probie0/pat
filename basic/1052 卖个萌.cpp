#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
int main()
{
	vector<string> vec_str(3);
	for (int i = 0; i < 3; i++)
		getline(cin, vec_str[i]);
	int pos1 = 0, pos2 = 0;
	vector<vector<string>> vec;
	for (int k = 0; k < 3; k++)
	{
		vector<string> temp;
		for (int i = 0; i < vec_str[k].size(); i++)
		{
			if (vec_str[k][i] == '[')
				pos1 = i + 1;
			if (vec_str[k][i] == ']')
			{
				pos2 = i;
				temp.push_back(vec_str[k].substr(pos1, pos2 - pos1));
			}
		}
		vec.push_back(temp);
	}
	int N;
	cin >> N;
	stringstream ss;
	for (int i = 0; i < N; i++)
	{
		vector<int> indices;
		indices.reserve(5);
		for (int j = 0; j < 5; j++)
		{
			int temp; cin >> temp;
			indices.push_back(temp-1);
		}
		if (indices[0] >= vec[0].size() || indices[4] >= vec[0].size() ||
			indices[1] >= vec[1].size() || indices[3] >= vec[1].size() || indices[2] >= vec[2].size())
			ss << "Are you kidding me? @\\/@\n";
		else
			ss << vec[0][indices[0]] << '(' << vec[1][indices[1]] << vec[2][indices[2]] << vec[1][indices[3]]
			<< ')' << vec[0][indices[4]] << '\n';
	}
	cout << ss.str();
	system("pause");
    return 0;
}