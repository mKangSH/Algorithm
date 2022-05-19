#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
	vector<vector<int>> memory(101);

	for (int i = 0; i < 10; ++i)
		memory[1].push_back(1);

	memory[1][0] = 0;

	int n;

	cin >> n;
	
	for (int lines = 2; lines < n+1; ++lines)
	{
		for (int i = 0; i < 10; ++i)
		{
			if (i == 0)
				memory[lines].push_back(memory[lines - 1][i + 1]);

			else if (i == 9)
				memory[lines].push_back(memory[lines - 1][i - 1]);

			else
				memory[lines].push_back(memory[lines - 1][i - 1] + memory[lines - 1][i + 1]);

			memory[lines][i] %= 1000000000;
		}
	}

	int sum = 0;

	for (int i = 0; i < 10; ++i)
		sum = (sum + memory[n][i]) % 1000000000;

	cout << sum;
}