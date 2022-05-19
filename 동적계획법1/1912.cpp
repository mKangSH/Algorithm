#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	int n, temp, mx = 0, acc = 0;

	cin >> n;
	ios::sync_with_stdio(false);

	for (int i = 0; i < n; ++i)
	{
		cin >> temp;

		mx = max(mx + temp, temp);
		v.push_back(mx);
	}

	cout << *max_element(v.begin(), v.end());

	return 0;
}