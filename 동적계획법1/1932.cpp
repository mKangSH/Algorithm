#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<vector<int>> v(501);

	int testCount, temp;

	cin >> testCount;
	cin >> temp;

	v[0].push_back(temp);

	for (int i = 1; i < testCount; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			cin >> temp;

			v[i].push_back(temp);

			if (j == 0)
				v[i][j] += v[i - 1][j];

			else if (j == i)
				v[i][j] += v[i - 1][j - 1];

			else
				v[i][j] = max(v[i - 1][j - 1], v[i - 1][j]) + v[i][j];
		}
	}

	cout << *max_element(v[testCount - 1].begin(), v[testCount - 1].end()) << endl;
}