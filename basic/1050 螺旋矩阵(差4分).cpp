#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<int> vec(N,0);
	for (int i = 0; i < N; i++)
		cin >> vec[i];
	sort(vec.rbegin(), vec.rend());
	int m, n;
	for (int j = sqrt(N); j >= 1; j--)  //求m和n
	{
		if (N % j == 0)
		{
			n = j; break;
		}
	}
	m = N / n;
	//cout << m << ' ' << n;
	//cout << endl;

	
	vector<int> row_indices, col_indices;
	row_indices.reserve(N);
	col_indices.reserve(N);
	int row_index = 0, col_index = 0;
	int row_max = m, col_max = n;
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < col_max - 1; i++)
			row_indices.push_back(row_index);
		for (int i = 0; i < row_max - 1; i++)
			row_indices.push_back(row_index++);
		for (int i = 0; i < col_max - 1; i++)
			row_indices.push_back(row_index);
		for (int i = 0; i < row_max - 1; i++)
			row_indices.push_back(row_index--);
		row_index++;
		row_max -= 2;
		col_max -= 2;
	}
	row_max = m, col_max = n;
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < col_max - 1; i++)
			col_indices.push_back(col_index++);
		for (int i = 0; i < row_max - 1; i++)
			col_indices.push_back(col_index);
		for (int i = 0; i < col_max - 1; i++)
			col_indices.push_back(col_index--);
		for (int i = 0; i < row_max - 1; i++)
			col_indices.push_back(col_index);
		col_index++;
		row_max -= 2;
		col_max -= 2;
	}
	/*
	for (int i = 0; i < row_indices.size(); i++)
		cout << row_indices[i] + 1 << ' ';
	cout << endl;
	for (auto e : col_indices)
		cout << e +1 << ' ';
	*/

	vector<vector<int>> matrix(m);         //初始化矩阵
	matrix.reserve(m);
	for (int i = 0; i < m; i++)
	{
		matrix[i].resize(n);
		matrix[i].reserve(n);
	}

	for (int i = 0; i < N; i++)
	{
		row_index = row_indices[i];
		col_index = col_indices[i];
		matrix[row_index][col_index] = vec[i];
	}

//	cout << '\n';
	for (int i = 0; i < m; i++)
	{
		int j = 0;
		for (j; j < n-1; j++)
			cout << matrix[i][j] << ' ';
		cout << matrix[i][j];
		cout << '\n';
	}

	system("pause");
	return 0;
}