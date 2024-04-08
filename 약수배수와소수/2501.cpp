#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	vector<int> factors;
	factors.reserve(100 * 2);

	int number = 0, idx;
	cin >> number >> idx;
	for (int i = 1; i <= sqrt(number); i++)
	{
		if (number % i == 0)
		{
			factors.push_back(i);
		}
	}

	size_t size = factors.size();
	for (size_t i = 0; i < size; i++)
	{
		if ((factors[(size - 1) - i] * factors[(size - 1) - i]) == number)
		{
			continue;
		}

		factors.push_back(number / factors[(size - 1) - i]);
	}

	if (factors.size() < idx)
	{
		cout << "0";
	}
	else
	{
		cout << factors[idx - 1];
	}
}