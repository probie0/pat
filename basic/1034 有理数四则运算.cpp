#include<iostream>
#include<stdlib.h>
#include<string>
#include<sstream>
#include<algorithm>
#include<iterator>
#include<cmath>
using namespace std;

class Fraction
{
public:
	Fraction(string &str)
	{
		string str_numerator, str_denominator;
		string::iterator it = find(str.begin(), str.end(), '/');
		copy(str.begin(), it, back_inserter(str_numerator));
		copy(it + 1, str.end(), back_inserter(str_denominator));
		numerator = str2int(str_numerator);
		denominator = str2int(str_denominator);
	}
	Fraction(long n, long d) :numerator{ n }, denominator{ d } {}
	Fraction operator+(const Fraction &f)const
	{
		long d1 = denominator, d2 = f.denominator;
		long n1 = numerator, n2 = f.numerator;
		long d_result; long n_result;
		if (denominator != f.denominator)
		{
			d_result = d1*d2;
			n_result = n1*d2 + n2*d1;
		}
		else
		{
			d_result = d1;
			n_result = n1 + n2;
		}
		return Fraction(n_result, d_result);
	}
	Fraction operator-(const Fraction &f)const
	{
		long d1 = denominator, d2 = f.denominator;
		long n1 = numerator, n2 = f.numerator;
		long d_result; long n_result;
		if (denominator != f.denominator)
		{
			d_result = d1*d2;
			n_result = n1*d2 - n2*d1;
		}
		else
		{
			d_result = d1;
			n_result = n1 - n2;
		}
		return Fraction(n_result, d_result);
	}
	Fraction operator*(const Fraction &f)const
	{
		long n_result = numerator*f.numerator;
		long d_result = denominator*f.denominator;
		return Fraction(n_result, d_result);
	}
	Fraction operator/(const Fraction &f)const
	{
		long n_result = numerator*f.denominator;
		long d_result = denominator*f.numerator;
		if (d_result < 0)
			return Fraction(-n_result, -d_result);
		else
			return Fraction(n_result, d_result);
	}
	string toString()
	{
		
		if (denominator == 0)
			return "Inf";
		string str_integer = to_string(integer) + ' ';
		string str_f = to_string(numerator) + '/' + to_string(denominator);
		if (integer == 0)
			str_integer = "";
		if (numerator == 0)
			str_f = "";
		string out = str_integer + str_f;
		if (out.back() == ' ')
			out.erase(out.size() - 1, 1);
		if(numerator < 0 || integer < 0)
			out = '(' + out + ')';
		if (out == "")
			out = '0';
		return out;
	}
	inline bool isNegative()
	{
		return numerator < 0;
	}
	long str2int(string str)
	{
		long out;
		stringstream ss;
		ss << str; ss >> out;
		return out;
	}
	long getGCD(long a, long b)     //最大公因数
	{
		int c = 1;
		while (c != 0)
		{
			c = a%b;
			a = b; b = c;
		}
		return a;
	}
	inline long getLCM(long a, long b)
	{
		return a*b / getGCD(a, b);
	}
	void simplify()
	{
		if (denominator == 0)
			return;
		long GCD = getGCD(abs(numerator), abs(denominator));
		denominator = abs(denominator / GCD);
		if (numerator < 0)
			numerator = -abs(numerator / GCD); 
		else 
			numerator = numerator / GCD;
		if (abs(numerator) < abs(denominator))
			return;
		integer = numerator / denominator;
		numerator = abs(numerator) % denominator;
	}
	long numerator;
	long denominator;
	long integer = 0;
};
int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	Fraction f1(str1), f2(str2);
	Fraction f_sum = f1 + f2, f_diff = f1 - f2;
	Fraction f_product = f1 * f2; Fraction f_quotient = f1 / f2;
	f_sum.simplify(); f_diff.simplify();
	f_product.simplify(); f_quotient.simplify();
	f1.simplify(); f2.simplify();
	str1 = f1.toString(); str2 = f2.toString();
	cout << str1 + " + " + str2 + " = " << f_sum.toString() << '\n';
	cout << str1 + " - " + str2 + " = " << f_diff.toString() << '\n';
	cout << str1 + " * " + str2 + " = " << f_product.toString() << '\n';
	cout << str1 + " / " + str2 + " = " << f_quotient.toString() << '\n';
	system("pause");
	return 0;
}