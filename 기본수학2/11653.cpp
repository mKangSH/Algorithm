#include <iostream>
#include <cmath>
using namespace std;

int func(int x)
{
	int end = x;

	if (x == 0) return 0;
	if (x == 1) return 0;

	for (int i = 2; i <= end; i++)
	{
		if (x % i == 0)
		{
			cout << i << endl;
			return func(x / i);
		}
	}
}

int main(void)
{
	int N;

	cin >> N;

	func(N);

	return 0;
}