#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool IsPrime(long long number)
{
	for (long long i = 2; i * i <= number; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		long long number;
		cin >> number;

		if (number == 0 || number == 1 || number == 2)
		{
			cout << "2\n";
		}
		else if (number == 3)
		{
			cout << "3\n";
		}
		else
		{
			while (IsPrime(number) == false)
			{
				number++;
			}
			cout << number << '\n';
		}
	}
}