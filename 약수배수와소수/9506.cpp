#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	vector<int> factors;
	factors.reserve(1000);

	while (true)
	{
		int number;
		cin >> number;

		if (number == -1)
		{
			break;
		}

		for (int i = 1; i * i <= number; i++)
		{
			if (number % i == 0)
			{
				factors.push_back(i);
			}
		}

		int sum = 0;
		size_t size = factors.size();
		for (size_t i = 0; i < size; i++)
		{
			sum += factors[size - 1 - i];
			if (number == factors[size - 1 - i] * factors[size - 1 - i] || number == number / factors[size - 1 - i])
			{
				continue;
			}

			sum += (number / factors[size - 1 - i]);
			factors.push_back(number / factors[size - 1 - i]);
		}

		if (sum == number)
		{
			cout << number << " = ";
			for (size_t i = 0; i < factors.size() - 1; i++)
			{
				cout << factors[i] << " + ";
			}
			cout << factors[factors.size() - 1] << '\n';
		}
		else
		{
			cout << number << " is NOT perfect." << '\n';
		}
		
		factors.clear();
	}
}