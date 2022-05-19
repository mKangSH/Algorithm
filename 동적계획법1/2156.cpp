#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> a(10001, 0), b(10001, 0);

	int testCount, temp;

	cin >> testCount;

	for (int i = 0; i < testCount; ++i)
	{
		cin >> temp;

		a[i] = temp;
	}

	if (testCount == 1)
	{
		b[testCount - 1] = a[0];
	}

	else if (testCount == 2)
	{
		b[testCount - 1] = a[0] + a[1];
	}

	else
	{
		b[0] = a[0];
		b[1] = a[0] + a[1];

		for (int i = 2; i < testCount; ++i)
		{
			b[i] = max(b[i - 2] + a[i], max(b[i - 3] + a[i - 1] + a[i], b[i-1]));
		}
	}

	cout << b[testCount - 1] << endl;
}