#include <iostream>
using namespace std;

uint64_t memory[101] = { 0 };

uint64_t calculator(int n)
{
	if (n == 1) return 1;
	else if (n == 2) return 1;
	else if (n == 3) return 1;
	else if (memory[n] != 0) return memory[n];
	return memory[n] = calculator(n - 2) + calculator(n - 3);
}

int main()
{
	int testCount, N;

	cin >> testCount;

	for (int i = 0; i < testCount; ++i)
	{
		cin >> N;

		cout << calculator(N) << endl;
	}
}