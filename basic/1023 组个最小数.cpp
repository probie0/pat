#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> vec; vec.reserve(50);
    for(int i = 0; i <= 9; i++)
    {
        int e; cin >> e;
        for(int j = 0; j < e; j++)
            vec.push_back(i);
    }
    sort(vec.begin(), vec.end());
    if(vec[0] == 0)
    {
        for(int i = 1; i < vec.size(); i++)
        {
            if(vec[i] != 0)
                {
                    int temp = vec[0];
                    vec[0] = vec[i];
                    vec[i] = temp;
                    break;
                }
        }
    }
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i];

    return 0;
}
