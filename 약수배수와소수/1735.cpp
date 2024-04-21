#include <iostream>
using namespace std;

int GetGreatestCommonDivisor(int a, int b)
{
	int remain;

	while (b != 0)
	{
		remain = a % b;
		a = b;
		b = remain;
	}

	return a;
}

int main()
{
	int numerator1, denominator1;
	cin >> numerator1 >> denominator1;

	int gcd1 = GetGreatestCommonDivisor(numerator1, denominator1);
	numerator1 /= gcd1;
	denominator1 /= gcd1;

	int numerator2, denominator2;
	cin >> numerator2 >> denominator2;

	int gcd2 = GetGreatestCommonDivisor(numerator2, denominator2);
	numerator2 /= gcd2;
	denominator2 /= gcd2;

	int denominator = denominator1 * denominator2 / GetGreatestCommonDivisor(denominator1, denominator2);
	int numerator = (numerator1 * (denominator / denominator1)) + (numerator2 * (denominator / denominator2));

	int gcd = GetGreatestCommonDivisor(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;

	cout << numerator << " " << denominator;
}