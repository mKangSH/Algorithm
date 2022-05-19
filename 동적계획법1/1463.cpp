#include <iostream>
#include <vector>
using namespace std;

int memory[1000001] = { 0 };
int tries, temp;

int recursive(int n)
{
	if (n == 1) return 0;
	if (n == 2) return 1;
	if (n == 3) return 1;

	if (memory[n] != 0) return memory[n];

	if (n % 6 == 0)
	{
		return memory[n] = min(min(recursive(n / 3), recursive(n / 2)), recursive(n - 1)) + 1;
	}

	else if (n % 3 == 0)
	{
		return memory[n] = min(recursive(n / 3), recursive(n -1)) + 1;
	}

	else if (n % 2 == 0)
	{
		return memory[n] = min(recursive(n / 2), recursive(n -1)) + 1;
	}

	else return memory[n] = 1 + recursive(n - 1);
}

int main()
{
	int N;

	cin >> N;

	cout << recursive(N);

	return 0;
}