#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string str_n;
    cin >> str_n;
    vector<int> vec(10,0);
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < str_n.size(); j++)
        {
            if(i == int(str_n[j] - '0'))
                vec[i]++;
        }
    }
    for(int i = 0; i < vec.size(); i++)
    {
        if(vec[i] != 0)
            cout << i << ":" << vec[i] << "\n";
    }
    return 0;
}
