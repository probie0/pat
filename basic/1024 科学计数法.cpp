#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<stdlib.h>
#include<iterator>
using namespace std;

int main()
{
    string str;
    cin >> str;
    string::iterator it_E = find(str.begin(), str.end(), 'E');
    string str1 = "", str2 = "";
    copy(str.begin(), it_E, back_inserter(str1));
    copy(it_E+1, str.end(), back_inserter(str2));
    double n1 = 0, n2 = 0;
    stringstream ss;
    ss << str1; ss >> n1; ss.clear();ss.str("");
    ss << str2; ss >> n2;
    double dou_result; string result;
    result = str1;
	if (n2 != 0)
	{
		result.erase(2, 1);
		if (str2[0] == '-')
		{
			result.insert(1, "0." + string(-n2 - 1, '0'));
		}
		else if (str2[0] == '+')
		{
			if (n2 - (str1.size() - 3) >= 0)
			{
				result.append(n2 - (str1.size() - 3), '0');
			}
			else
				result.insert(2+n2, ".");
		}
	}
	if (str1[0] == '+')
		result.erase(0, 1);

    cout << result;
	system("pause");
    return 0;
}
