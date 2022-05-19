#include <iostream>
using namespace std;

pair<int, int> a[42];

int main()
{
	int testCount = 0;
	cin >> testCount;

	a[0] = { 1, 0 };
	a[1] = { 0, 1 };
	a[2] = { 1, 1 };

	for (int i = 3; i < 42; ++i)
	{
		a[i].first = a[i - 2].first + a[i - 1].first;
		a[i].second = a[i - 2].second + a[i - 1].second;
	}

	for (int i = 0; i < testCount; ++i)
	{
		int N;
		cin >> N;

		cout << a[N].first << ' ' << a[N].second << endl;
	}
}