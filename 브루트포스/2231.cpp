#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int memory[1000001] = { 0 };

int main()
{
	int result = 0, input;
	for (int i = 1; i < 1000001; ++i)
	{
		result = i + i % 10;

		for (int j = i / 10; j > 0; j = j / 10)
		{
			result += j % 10;
		}

		if (memory[result] == 0)
			memory[result] = i;
	}

	cin >> input;

	cout << memory[input] << endl;

	return 0;
}