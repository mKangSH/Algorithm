#include <iostream>
//2775
using namespace std;

void find(int n, int d[])
{
	int temp[14] = { 0 };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			temp[i] += d[j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		d[i] = temp[i];
	}
}

int main(void)
{
	int d[14];
	int T, k, n;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		for (int i = 0; i < 14; i++)
		{
			d[i] = i + 1;
		}

		cin >> k >> n;

		for (int j = 0; j < k; j++)
		{
			find(n, d);
		}

		cout << d[n - 1] << endl;
	}
}