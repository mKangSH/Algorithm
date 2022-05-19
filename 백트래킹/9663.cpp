#include <iostream>
#include <vector>
using namespace std;

int s = 0;

bool check(const vector<int>& v, const int count)
{
	for (int i = 0; i < count; ++i)
	{
		if (v[i] == v[count] || abs(v[count] - v[i]) == (count - i))
			return false;
	}

	return true;
}

void nQueen(vector<int>& v, int count, const int n)
{
	if (n == count)
	{
		++s;

		return;
	}

	else
	{
		for (int i = 0; i < n; ++i)
		{
			v[count] = i;

			if (check(v, count))
				nQueen(v, count + 1, n);
		}
	}
}

int main()
{
	int n;
	vector<int> v(15, -1);

	cin >> n;

	nQueen(v, 0, n);

	cout << s;
}