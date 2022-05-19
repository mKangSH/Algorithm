#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
	return a < b;
}

int main(void)
{
	int testCount, x, prev = 1234567890, index = 0;
	vector<int> v, vCopy;

	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	cin >> testCount;

	for (int i = 0; i < testCount; ++i)
	{
		cin >> x;

		v.push_back(x);
	}

	vCopy = v;

	sort(vCopy.begin(), vCopy.end(), compare);

	auto iter = unique(vCopy.begin(), vCopy.end());

	vCopy.erase(iter, vCopy.end());

	for (int i = 0; i < testCount; ++i)
	{
		auto iter = lower_bound(vCopy.begin(), vCopy.end(), v[i]);

		cout << iter - vCopy.begin() << ' ';
	}

	return 0;
}