#include <iostream>
using namespace std;

bool isPrimeNumber(int x)
{
	if (x == 1) return false;

	for (int i = 2; i < x; i++)
	{
		if (x % i == 0) return false;
	}

	return true;
}

int main(void)
{
	int N, count = 0, x;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;

		if (isPrimeNumber(x))
		{
			++count;
		}
	}

	cout << count << endl;
}