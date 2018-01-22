#include <iostream>  
#include<stdlib.h>
using namespace std;
int main()
{
	int a = 0, n = 0;
	cin >> a >> n;
	if (n != 0)
		cout << a*n << ' ' << n - 1;
	else cout << "0 0";
	while (cin >> a >> n)
		if (n != 0)
			cout << ' ' << a*n << ' ' << n - 1;
	system("pause");
	return 0;
}