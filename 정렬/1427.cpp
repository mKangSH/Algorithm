#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int main(void)
{
	int n, tmp;
	vector<int> v;

	cin >> n;

	while (n != 0)
	{
		tmp = n % 10;

		v.push_back(tmp);

		n /= 10;
	}

	sort(v.begin(), v.end(), compare);

	for (auto iter : v)
	{
		cout << iter;
	}

	cout << endl;

	return 0;
}