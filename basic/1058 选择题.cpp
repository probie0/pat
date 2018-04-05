#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
struct Ques
{
	int score; int num_all; int num_r; string ans;
};
struct Res
{
	int num_r; string ans;
};
void inputQues(Ques &q)                 //用于输入题目信息（输入Ques结构体）
{
	cin >> q.score >> q.num_all >> q.num_r;
	q.ans.reserve(q.num_r);
	char c;
	for (int i = 0; i < q.num_r; i++)
	{
		cin >> c;
		q.ans.push_back(c);
	}
}
void inputRes(Res &r)        //用于输入学生的答题信息（输入Res结构体）
{
	char c;
	cin >> c;
	cin >> r.num_r;
	r.ans.reserve(r.num_r);
	for (int i = 0; i < r.num_r; i++)
	{
		cin >> c;
		r.ans.push_back(c);
	}
	cin >> c;
}
bool isRight(Ques &q, Res &r)
{
	if (q.num_r != r.num_r)
		return false;
	if (q.ans != r.ans)
		return false;
	return true;
}
int main()
{
	int N, M;
	cin >> N >> M;
	vector<Ques> v_ques; v_ques.reserve(M);
	for (int i = 0; i < M; i++)  //输入每道题目的信息
	{
		Ques q;
		inputQues(q);
		v_ques.push_back(q);
	}
	vector<int> stuScore(N,0);
	vector<int> wrongTimesOfQues(M, 0);
	for (int i = 0; i < N; i++)     //学生
	{
		for (int j = 0; j < M; j++) //学生的答案
		{
			Res r; Ques q = v_ques[j];
			inputRes(r);
			if (isRight(q, r))
			{
				stuScore[i] += q.score;
			}
			else
				wrongTimesOfQues[j]++;
		}
	}
	for (auto e : stuScore)
		cout << e << '\n';
	auto iterMax = max_element(wrongTimesOfQues.begin(), wrongTimesOfQues.end());
	int maxTimes = *iterMax;
	if (maxTimes == 0)
		cout << "Too simple";
	else
	{
		cout << maxTimes;
		for (int i = 0; i < M; i++)
		{
			if (wrongTimesOfQues[i] == maxTimes)
				cout << ' ' << i+1;
		}
	}

	system("pause");
	return 0;
}