#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	string number;
	int numberSystem;
	cin >> number >> numberSystem;

	int decimalNumber = 0;
	for (size_t i = 0; i < number.length(); i++)
	{
		int coefficient;
		if (number[(number.length() - 1) - i] >= 'A' && number[(number.length() - 1) - i] <= 'Z')
		{
			coefficient = number[(number.length() - 1) - i] - 'A' + 10;
		}
		else
		{
			coefficient = number[(number.length() - 1) - i] - '0';
		}

		decimalNumber += coefficient * pow(numberSystem, i);
	}

	cout << decimalNumber;
}