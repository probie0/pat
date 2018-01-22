#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

bool isPrime(int x)
{
	if (x == 2)
	{
		return true;
	}
	for (int i = 2; i < sqrt(x)+1; i++)
	{
		if (x%i == 0)
		{
			return false;
		}
	}
	return true;
}

int findNextPrime(int prime)
{
	int x = prime+1;
	while (isPrime(x) == false)
	{
		x++;
	}
	return x;
}


int main()
{
	vector<int> vec_primes;
	int m, n;
	cin >> m >> n;
	
	int count = 0;
	int prime = 2;
	vec_primes.push_back(2);

	while (count <= n)
	{
		prime = findNextPrime(prime);
		vec_primes.push_back(prime);
		count++;
	}




	for (int i = m - 1; i < n; i++)
	{
		if ((i - m + 2) % 10 == 0 && i!=m-1)
		{
			cout << vec_primes[i] << endl;
		}
		else if (i == n - 1)
		{
			cout << vec_primes[i];
		}
		else
		{
			cout << vec_primes[i] << " ";
		}
	}
	return 0;
}

