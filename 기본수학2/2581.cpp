#include <iostream>
#include <cmath>
using namespace std;

int minN = 100000, sum = 0;

bool isPrimeNumber(int x)
{
	int end = (int) sqrt(x);
	
	if (x == 1) return false;

	for (int i = 2; i <= end; i++)
	{
		if (x % i == 0) return false;
	}

	if (minN >= x)
		minN = x;

	sum += x;

	return true;
}

int main(void)
{
	int M, N, count = 0, x;

	cin >> M >> N;

	for (int i = M; i <= N; i++)
	{
		if (isPrimeNumber(i))
		{
			++count;
		}
	}

	if (count == 0)
		cout << -1 << endl;

	else
		cout << sum << '\n' << minN << endl;
}